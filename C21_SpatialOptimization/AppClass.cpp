#include "AppClass.h"
using namespace BTX;
void Application::InitVariables(void)
{
	//Alberto needed this at this position for software recording.
	//m_pWindow->setPosition(sf::Vector2i(710, 0));

	//Set the position and target of the camera
	m_pCameraMngr->SetPositionTargetAndUpward(
		vector3(0.0f, 0.0f, 100.0f), //Position
		vector3(0.0f, 0.0f, 99.0f),	//Target
		AXIS_Y);					//Up

	//Entity Manager
	m_pEntityMngr = EntityManager::GetInstance();

	uint uInstances = 500;
	int nSquare = static_cast<int>(std::sqrt(uInstances));
	uInstances = nSquare * nSquare;
	uint uIndex = 0;
	for (int i = 0; i < nSquare; i++)
	{
		for (int j = 0; j < nSquare; j++)
		{
			m_pEntityMngr->AddEntity("Minecraft\\Cube.obj");
			vector3 v3Position = vector3(glm::sphericalRand(34.0f));
			matrix4 m4Position = glm::translate(v3Position);
			m_pEntityMngr->SetModelMatrix(m4Position);

			bool bAllEntitiesInTheirOwnSpace = true;
			if (bAllEntitiesInTheirOwnSpace)
			{
				//We will divide the space in only 4 parts
				if (v3Position.x < 0.0f)
				{
					//Left of -17
					if (v3Position.x < -17.0f)
						m_pEntityMngr->AddDimension(-1, 1);
					//right of -17 left of 0
					else
						m_pEntityMngr->AddDimension(-1, 2);
				}
				else if (v3Position.x > 0.0f)
				{
					//right of 0 left of 17
					if (v3Position.x > 17.0f)
						m_pEntityMngr->AddDimension(-1, 3);
					//left of 17
					else
						m_pEntityMngr->AddDimension(-1, 4);
				}
			}
			else 
			{
				//All entities will be living in their own space, great performance... because
				//we are doing nothing (other than asking entities what space they live in)
				m_pEntityMngr->AddDimension(-1, uIndex);
				++uIndex;
			}
		
		}
	}
	m_pEntityMngr->Update();
	//steve
	//m_pEntityMngr->AddEntity("Minecraft\\Steve.obj", "Steve");
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the ArcBall active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
	
	//Update Entity Manager
	m_pEntityMngr->Update();

	m_pModelMngr->AddGridToRenderList(glm::rotate(IDENTITY_M4, 1.5708f, AXIS_Y));
	m_pModelMngr->AddGridToRenderList(glm::translate(vector3(-17.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, 1.5708f, AXIS_Y));
	m_pModelMngr->AddGridToRenderList(glm::translate(vector3(17.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, 1.5708f, AXIS_Y));
		
	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();
	
	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release GUI
	ShutdownGUI();
}