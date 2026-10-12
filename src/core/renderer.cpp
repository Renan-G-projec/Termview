// Ad Maiorem Dei Gloriam!
#include "core/renderer.hpp"

void Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(DrawCommand command)
{
    mDrawCommands.emplace_back(command);
}

void Renderer::drawAll()
{
    sortDrawCommands();
    Shader *currentShader;
    Mesh *currentMesh;
    glm::mat4 cameraMatrix = mCurrentCamera.getMatrix();

    for (auto drawCommand : mDrawCommands)
    {
        glm::mat4 modelMatrix{1.0f};
        modelMatrix = glm::translate(modelMatrix, drawCommand.transform->position);
        modelMatrix = glm::scale(modelMatrix, drawCommand.transform->scale);

        if (drawCommand.shader != currentShader)
        {
            currentShader = drawCommand.shader;
            currentShader->activate();
            currentShader->setUniformMatrix(cameraMatrix * modelMatrix);
        }

        if (drawCommand.mesh != currentMesh)
        {
            currentMesh = drawCommand.mesh;
            currentMesh->lazyBind();
        }

        currentMesh->lazyRender();
    }
    

    mDrawCommands.clear();
}

void Renderer::sortDrawCommands() 
{
    std::sort(mDrawCommands.begin(), mDrawCommands.end(), [](DrawCommand firstCommand, DrawCommand secondCommand){
        if (firstCommand.shader != secondCommand.shader) return firstCommand.shader < secondCommand.shader;
        if (firstCommand.mesh != secondCommand.mesh) return firstCommand.mesh < secondCommand.mesh;
        return false;
    });
}