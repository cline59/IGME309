#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(1.0f, C_BLACK);
		
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	static float displacement = 0.0f;
	matrix4 m4Model = glm::translate(IDENTITY_M4, vector3(displacement, 0.0f, 0.0f));

	
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, 0.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, 0.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, 0.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, 0.0f, 0.0f)));

	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(0.0f, 1.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 1.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 1.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(10.0f, 1.0f, 0.0f)));

	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(0.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(5.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 2.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(10.0f, 2.0f, 0.0f)));

	for (uint count = 0; count < 11; ++count)
	{
		m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(count, 3.0f, 0.0f)));
	}

	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(1.0f, 4.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 4.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, 4.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(5.0f, 4.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, 4.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 4.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(9.0f, 4.0f, 0.0f)));

	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, 6.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, 6.0f, 0.0f)));

	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 7.0f, 0.0f)));
	m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 7.0f, 0.0f)));

	for (uint count = 0; count < 11; ++count)
	{
		m_pMesh->Render(m4Projection, m4View, glm::translate(m4Model, vector3(count, 5.0f, 0.0f)));
	}

	displacement += 0.01f;

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
	//Release meshes
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}