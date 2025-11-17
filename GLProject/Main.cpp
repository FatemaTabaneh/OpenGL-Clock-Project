// GLProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <learnopengl/shader_m.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Polygon.cpp"

using namespace glm;

int width = 800;
int height = 600;

vec3 cameraPos = vec3(0.0f, 0.0f, 4.0f);
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
    const float cameraSpeed = 0.001f; 
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		cameraPos += cross(cameraFront,normalize(cross(cameraFront, cameraUp))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		cameraPos -= cross(cameraFront, normalize(cross(cameraFront, cameraUp))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		mat4 rotationMatrix = glm::rotate(mat4(1.0f), 0.0001f, vec3(0.0f, 1.0f, 0.0f));
		vec4 rotatedVectorHomogeneous = rotationMatrix * vec4(cameraFront, 1.0f);
		cameraFront = vec3(rotatedVectorHomogeneous);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		mat4 rotationMatrix = glm::rotate(mat4(1.0f), 0.0001f, vec3(0.0f, -1.0f, 0.0f));
		vec4 rotatedVectorHomogeneous = rotationMatrix * vec4(cameraFront, 1.0f);
		cameraFront = vec3(rotatedVectorHomogeneous);
	}
}
std::vector<vec3> createCircle(float radius, int segments, float z = 0.0f) {
	std::vector<vec3> verts;
	for (int i = 0; i < segments; i++) {
		float angle = 2.0f * 3.1415926f * i / segments;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		verts.push_back(vec3(x, y, z));
	}
	return verts;
}


int main()
{
	//////////////////////////////////////////////////////////////////
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(width, height, "Lecture 3", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glEnable(GL_DEPTH_TEST);

	Shader ourShader("./shaders/vs/L3.vs", "./shaders/fs/L3.fs");
	/////////////////////////////////////////////////////////////////


	std::vector<vec3> vertices1 = {};
	vertices1.push_back(vec3(0.5f, -0.5f, 0.0f));
	vertices1.push_back(vec3(-0.5f, -0.5f, 0.0f));
	vertices1.push_back(vec3(-0.5f, 0.5f, 0.0f));
	vertices1.push_back(vec3(0.5f, 0.5f, 0.0f));
	Polygon Polygon1 = Polygon(vertices1, vec3(50 / 255.0f, 60 / 255.0f, 60 / 255.0f));

	std::vector<vec3> vertices2 = {};
	vertices2.push_back(vec3(0.5f, -0.5f, 0.1f));
	vertices2.push_back(vec3(-0.5f, -0.5f, 0.1f));
	vertices2.push_back(vec3(-0.5f, 0.5f, 0.1f));
	vertices2.push_back(vec3(0.5f, 0.5f, 0.1f));
	Polygon Polygon2 = Polygon(vertices2, vec3(51 / 255.0f, 68 / 255.0f, 67/ 255.0f));

	std::vector<vec3> vertices3 = {};
	vertices3.push_back(vec3(-0.5f, -0.5f, 0.0f));
	vertices3.push_back(vec3(-0.5f, -0.5f, 0.1f));
	vertices3.push_back(vec3(-0.5f, 0.5f, 0.1f));
	vertices3.push_back(vec3(-0.5f, 0.5f, 0.0f));
	Polygon Polygon3 = Polygon(vertices3, vec3(40 / 255.0f, 68 / 255.0f, 67 / 255.0f));

	std::vector<vec3> vertices4 = {};
	vertices4.push_back(vec3(0.5f, -0.5f, 0.0f));
	vertices4.push_back(vec3(0.5f, -0.5f, 0.1f));
	vertices4.push_back(vec3(0.5f, 0.5f, 0.1f));
	vertices4.push_back(vec3(0.5f, 0.5f, 0.0f));
	Polygon Polygon4 = Polygon(vertices4, vec3(40 / 255.0f, 68 / 255.0f, 67 / 255.0f));

	std::vector<vec3> vertices5 = {};
	vertices5.push_back(vec3(-0.5f, 0.5f, 0.0f));
	vertices5.push_back(vec3(-0.5f, 0.5f, 0.1f));
	vertices5.push_back(vec3(0.5f, 0.5f, 0.1f));
	vertices5.push_back(vec3(0.5f, 0.5f, 0.0f));
	Polygon Polygon5 = Polygon(vertices5, vec3(40 / 255.0f, 68 / 255.0f, 67 / 255.0f));


	std::vector<vec3> vertices6 = {};
	vertices6.push_back(vec3(-0.5f, -0.5f, 0.0f));
	vertices6.push_back(vec3(-0.5f, -0.5f, 0.1f));
	vertices6.push_back(vec3(0.5f, -0.5f, 0.1f));
	vertices6.push_back(vec3(0.5f, -0.5f, 0.0f));
	Polygon Polygon6 = Polygon(vertices6, vec3(40 / 255.0f, 68 / 255.0f, 67 / 255.0f));
	////////////////////////////////////////„—»⁄ „‰ Ê—« 
	std::vector<vec3> vertices20 = {};
	vertices20.push_back(vec3(0.2f, -0.2f, -0.05f));
	vertices20.push_back(vec3(-0.2f, -0.2f, -0.05f));
	vertices20.push_back(vec3(-0.2f, 0.2f, -0.05f));
	vertices20.push_back(vec3(0.2f, 0.2f, -0.05f));
	Polygon Polygon20 = Polygon(vertices20, vec3(30 / 255.0f, 51 / 255.0f, 72 / 255.0f));

	std::vector<vec3> vertices21 = {};
	vertices21.push_back(vec3(-0.2f, -0.2f, 0.0f));
	vertices21.push_back(vec3(-0.2f, -0.2f, -0.05f));
	vertices21.push_back(vec3(-0.2f, 0.2f, -0.05f));
	vertices21.push_back(vec3(-0.2f, 0.2f, 0.0f));
	Polygon Polygon21 = Polygon(vertices21, vec3(30 / 255.0f, 51 / 255.0f, 72 / 255.0f));

	std::vector<vec3> vertices22 = {};
	vertices22.push_back(vec3(0.2f, -0.2f, 0.0f));
	vertices22.push_back(vec3(0.2f, -0.2f, -0.05f));
	vertices22.push_back(vec3(0.2f, 0.2f, -0.05f));
	vertices22.push_back(vec3(0.2f, 0.2f, 0.0f));
	Polygon Polygon22 = Polygon(vertices22, vec3(30 / 255.0f, 51 / 255.0f, 72 / 255.0f));

	std::vector<vec3> vertices23 = {};
	vertices23.push_back(vec3(-0.2f, 0.2f, 0.0f));
	vertices23.push_back(vec3(-0.2f, 0.2f, -0.05f));
	vertices23.push_back(vec3(0.2f, 0.2f, -0.05f));
	vertices23.push_back(vec3(0.2f, 0.2f, 0.0f));
	Polygon Polygon23 = Polygon(vertices23, vec3(30 / 255.0f, 51 / 255.0f, 72 / 255.0f));

	std::vector<vec3> vertices24 = {};
	vertices24.push_back(vec3(-0.2f, -0.2f, 0.0f));
	vertices24.push_back(vec3(-0.2f, -0.2f, -0.05f));
	vertices24.push_back(vec3(0.2f, -0.2f, -0.05f));
	vertices24.push_back(vec3(0.2f, -0.2f, 0.0f));
	Polygon Polygon24 = Polygon(vertices24, vec3(30 / 255.0f, 51 / 255.0f, 72 / 255.0f));

	std::vector<vec3> ballBack = createCircle(0.04f, 40);
	Polygon PolygonBallBack = Polygon(ballBack, vec3(1.0f, 1.0f, 1.0f));

	///////////////////////////
	std::vector<vec3> vertices7 = {};
	vertices7.push_back(vec3(0.45f, -0.45f, 0.11f));
	vertices7.push_back(vec3(-0.45f, -0.45f, 0.11f));
	vertices7.push_back(vec3(-0.45f, 0.45f, 0.11f));
	vertices7.push_back(vec3(0.45f, 0.45f, 0.11f));
	Polygon Polygon7 = Polygon(vertices7, vec3(30 / 255.0f, 51 / 255.0f, 72 / 255.0f));

	std::vector<vec3> vertices8 = {};
	vertices8.push_back(vec3(0.25f, -0.25f, 0.12f));
	vertices8.push_back(vec3(-0.25f, -0.25f, 0.12f));
	vertices8.push_back(vec3(-0.25f, 0.25f, 0.12f));
	vertices8.push_back(vec3(0.25f, 0.25f, 0.12f));
	Polygon Polygon8 = Polygon(vertices8, vec3(1.0f,1.0f, 1.0f));

	std::vector<vec3> vertices9 = {};
	vertices9.push_back(vec3(0.23f, -0.23f, 0.13f));
	vertices9.push_back(vec3(-0.23f, -0.23f, 0.13f));
	vertices9.push_back(vec3(-0.23f, 0.23f, 0.13f));
	vertices9.push_back(vec3(0.23f, 0.23f, 0.13f));
	Polygon Polygon9 = Polygon(vertices9, vec3(52/255.0f, 101/255.0f, 109/255.0f));

	std::vector<vec3> vertices10 = {};
	vertices10.push_back(vec3(0.01f, 0.0f, 0.05f));
	vertices10.push_back(vec3(0.01f, -1.0f, 0.05f));
	vertices10.push_back(vec3(-0.01f, -1.0f, 0.05f));
	vertices10.push_back(vec3(-0.01f, 0.0f, 0.05f));
	Polygon Polygon10 = Polygon(vertices10, vec3(1.0f, 1.0f, 1.0f));

	std::vector<vec3> vertices11 = {};
	vertices11.push_back(vec3(0.01f, 0.0f, 0.01f));
	vertices11.push_back(vec3(0.01f, -1.0f, 0.01f));
	vertices11.push_back(vec3(-0.01f, -1.0f, 0.01f));
	vertices11.push_back(vec3(-0.01f, 0.0f, 0.01f));
	Polygon Polygon11 = Polygon(vertices11, vec3(210 / 255.0f, 220 / 255.0f, 182 / 255.0f));

	std::vector<vec3> vertices12 = {};
	vertices12.push_back(vec3(0.01f, -1.0f, 0.05f));
	vertices12.push_back(vec3(0.01f, 0.0f, 0.05f));
	vertices12.push_back(vec3(-0.01f, 0.0f, 0.01f));
	vertices12.push_back(vec3(-0.01f, -1.0f, 0.01f));
	Polygon Polygon12 = Polygon(vertices12, vec3(210 / 255.0f, 220 / 255.0f, 182 / 255.0f));

	std::vector<vec3> vertices13 = {};
	vertices13.push_back(vec3(-0.01f, -1.0f, 0.05f));
	vertices13.push_back(vec3(-0.01f, 0.0f, 0.05f));
	vertices13.push_back(vec3(0.01f, 0.0f, 0.01f));
	vertices13.push_back(vec3(0.01f, -1.0f, 0.01f));
	Polygon Polygon13 = Polygon(vertices13, vec3(210 / 255.0f, 220 / 255.0f, 182 / 255.0f));


	std::vector<vec3> ballVerts = createCircle(0.1f, 40);
	Polygon PolygonBall=Polygon(ballVerts, vec3(1.0f, 1.0f, 1.0f)); 

	std::vector<vec3> ballVerts2 = createCircle(0.1f, 40);
	Polygon PolygonBall2 = Polygon(ballVerts2, vec3(1.0f, 1.0f, 1.0f));

	std::vector<vec3> pivotVerts = createCircle(0.02f, 40, 0.146f);
	Polygon PolygonPivot = Polygon(pivotVerts, vec3(1.0f, 1.0f, 1.0f));


	/////////////////////////////////////////////////////////////////////////
	std::vector<vec3> vertices100 = {};
	vertices100.push_back(vec3(0.45f, 0.0f, 0.112f));
	vertices100.push_back(vec3(0.45f, -0.01f, 0.112f));
	vertices100.push_back(vec3(0.4f, -0.01f, 0.112f));
	vertices100.push_back(vec3(0.4f, 0.0f, 0.112f));
	Polygon Polygon100 = Polygon(vertices100, vec3(1.0f, 1.0f, 1.0f));

	std::vector<vec3> vertices101 = {};
	vertices101.push_back(vec3(-0.45f, 0.0f, 0.112f));
	vertices101.push_back(vec3(-0.45f, -0.01f, 0.112f));
	vertices101.push_back(vec3(-0.4f, -0.01f, 0.112f));
	vertices101.push_back(vec3(-0.4f, 0.0f, 0.112f));
	Polygon Polygon101 = Polygon(vertices101, vec3(1.0f, 1.0f, 1.0f));

	std::vector<vec3> vertices102 = {};
	vertices102.push_back(vec3(-0.01f, -0.45f, 0.112f));
	vertices102.push_back(vec3(-0.01f, -0.4f, 0.112f));
	vertices102.push_back(vec3(0.01f, -0.4f, 0.112f));
	vertices102.push_back(vec3(0.01f, -0.45f, 0.112f));
	Polygon Polygon102 = Polygon(vertices102, vec3(1.0f, 1.0f, 1.0f));

	std::vector<vec3> vertices103 = {};
	vertices103.push_back(vec3(-0.01f, 0.45f, 0.112f));
	vertices103.push_back(vec3(-0.01f, 0.4f, 0.112f));
	vertices103.push_back(vec3(0.01f, 0.4f, 0.112f));
	vertices103.push_back(vec3(0.01f, 0.45f, 0.112f));
	Polygon Polygon103 = Polygon(vertices103, vec3(1.0f, 1.0f, 1.0f));

	float d = 0.1;
	std::vector<vec3> hour = {};
	hour.push_back(vec3(0.0f, -0.09f+d, 0.14f));
	hour.push_back(vec3(0.0f, -0.1f+d, 0.14f));
	hour.push_back(vec3(0.15f, -0.1f+d, 0.14f));
	hour.push_back(vec3(0.15f, -0.09f+d, 0.14f));
	Polygon PolygonHour = Polygon(hour, vec3(1.0f, 1.0f, 1.0f));

	std::vector<vec3> minut = {};
	minut.push_back(vec3(0.0f, -0.09f+d, 0.14f));
	minut.push_back(vec3(0.0f, -0.1f + d, 0.14f));
	minut.push_back(vec3(-0.25f, -0.1f + d, 0.14f));
	minut.push_back(vec3(-0.25f, -0.09f + d, 0.14f));
	Polygon PolygonMinut = Polygon(minut, vec3(1.0f, 1.0f, 1.0f));


	std::vector<vec3> second = {};
	second.push_back(vec3(-0.005f, -0.18f + d, 0.145f));
	second.push_back(vec3(0.005f, -0.18f + d, 0.145f));
	second.push_back(vec3(0.005f, 0.1f + d, 0.145f));
	second.push_back(vec3(-0.005f, 0.1f + d, 0.145f));
	Polygon PolygonSecond = Polygon(second, vec3(1.0f, 0.0f, 0.0f));



	ourShader.use();
	//////projection////////
	mat4 projection = mat4(1.0f);
	projection = perspective(radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	//projection = ortho(-(float)width, (float)width, -(float)height, (float)height, 0.01f, 100.0f);;
	ourShader.setMat4("projection", projection);

	while (!glfwWindowShouldClose(window))
	{
		////////////////////////////////////////////////
		processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		///////////////////view /////////////////////////
		mat4 view = mat4(1.0f);
		view = translate(view, vec3(0.0f, 0.0f, -3.0f));
		view = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		ourShader.setMat4("view", view);
		
		
		mat4 transformation = mat4(1.0f);
		transformation = translate(transformation, vec3(-0.5f, -0.1f, 0.0f));
		transformation = translate(transformation, vec3(0.5f, 0.5f, 0.0f));

		/*axis.transformation(transformation);
		axis.draw(ourShader);*/
		//transformation = rotate(transformation, (float)glfwGetTime(), vec3(1.0f, 1.0f, 1.0f));
		//transformation = glm::translate(transformation, glm::vec3(0.1f * glm::cos((float)glfwGetTime() * 1) * 10, 0.0f , 0.0f));


		Polygon1.transformation(transformation);
		Polygon1.draw(ourShader);

		Polygon2.transformation(transformation);
		Polygon2.draw(ourShader);
		
		Polygon3.transformation(transformation);
		Polygon3.draw(ourShader);
		
		Polygon4.transformation(transformation);
		Polygon4.draw(ourShader);
		
		Polygon5.transformation(transformation);
		Polygon5.draw(ourShader);
		
		Polygon6.transformation(transformation);
		Polygon6.draw(ourShader);

		Polygon7.transformation(transformation);
		Polygon7.draw(ourShader);

		Polygon8.transformation(transformation);
		Polygon8.draw(ourShader);

		Polygon9.transformation(transformation);
		Polygon9.draw(ourShader);


		float t = glfwGetTime();
		mat4 model = transformation;
		model = translate(model, vec3(0.0f, -0.4f, 0.0f)); 
		model = rotate(model, sin(t*4.5f) * glm::radians(30.0f), vec3(0.0f, 0.0f, 1.0f));

		Polygon10.transformation(model);
		Polygon10.draw(ourShader);

		Polygon11.transformation(model);
		Polygon11.draw(ourShader);

		Polygon12.transformation(model);
		Polygon12.draw(ourShader);

		Polygon13.transformation(model);
		Polygon13.draw(ourShader);


		mat4 ball = model;
		ball = translate(ball, vec3(0.0f, -0.87f, 0.05f));

		mat4 ballBack = transformation;
		ballBack = translate(ballBack, vec3(-0.05f, 0.1f, -0.06f));
		PolygonBallBack.transformation(ballBack);
		PolygonBallBack.draw(ourShader);

		PolygonBall.transformation(ball);
		PolygonBall.draw(ourShader);

		mat4 ball2 = model;
		ball2 = translate(ball2, vec3(0.0f, -0.87f, 0.01f));
		PolygonBall2.transformation(ball2);
		PolygonBall2.draw(ourShader);


		Polygon100.transformation(transformation);
		Polygon100.draw(ourShader);

		Polygon101.transformation(transformation);
		Polygon101.draw(ourShader);

		Polygon102.transformation(transformation);
		Polygon102.draw(ourShader);

		Polygon103.transformation(transformation);
		Polygon103.draw(ourShader);

		Polygon20.transformation(transformation);
		Polygon20.draw(ourShader);

		Polygon21.transformation(transformation);
		Polygon21.draw(ourShader);

		Polygon22.transformation(transformation);
		Polygon22.draw(ourShader);

		Polygon23.transformation(transformation);
		Polygon23.draw(ourShader);

		Polygon24.transformation(transformation);
		Polygon24.draw(ourShader);

		vec3 clockCenter = vec3(0.0f, -0.1f+d, 0.0f);

		mat4 pivotModel = transformation;
		pivotModel = translate(pivotModel, clockCenter);

		PolygonPivot.transformation(pivotModel);
		PolygonPivot.draw(ourShader);

		mat4 secModel = transformation;
		secModel = translate(secModel, clockCenter);          
		secModel = rotate(secModel, -t * glm::radians(6.0f), vec3(0, 0, 1));
		secModel = translate(secModel, -clockCenter);        
		PolygonSecond.transformation(secModel);
		PolygonSecond.draw(ourShader);

		float hourAngle = -t * glm::radians(30.0/3600.0f);
		mat4 hourModel = transformation;
		hourModel = translate(hourModel, clockCenter);
		hourModel = rotate(hourModel, hourAngle, vec3(0, 0, 1));   
		hourModel = translate(hourModel, -clockCenter);
		PolygonHour.transformation(hourModel);
		PolygonHour.draw(ourShader);


		float minAngle = -t * glm::radians(6.0/60.0f);
		mat4 minModel = transformation;
		minModel = translate(minModel, clockCenter);
		minModel = rotate(minModel, minAngle, vec3(0, 0, 1));   
		minModel = translate(minModel, -clockCenter);
		PolygonMinut.transformation(minModel);
		PolygonMinut.draw(ourShader);

		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}