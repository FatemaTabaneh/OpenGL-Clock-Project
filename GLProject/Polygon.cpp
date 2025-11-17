#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <learnopengl/shader_m.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Polygon {
private:
	glm::vec3 head;
	std::vector<glm::vec3> vertices;
	glm::vec3 color;
	glm::mat4 model;
	GLuint VAO;
	Polygon();

public:
	//Constractor
	Polygon(std::vector<glm::vec3> v, glm::vec3 c) {
		vertices = v;
		head = v.at(0);
		color = c;
		model = glm::mat4(1.0f);

		GLuint VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		glGenBuffers(1, &VBO);

		// position attribute
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
		glEnableVertexAttribArray(0);
		this->VAO = VAO;
	}
	//Function 1
	void transformation(glm::mat4 t) {
		model = t;
	}
	//Function 2
	void draw(Shader &shader)
	{
		shader.setVec3("objectColor", color);
		shader.setMat4("model", model);
		glBindVertexArray(this->VAO);
		glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());
	}
	void draw2(Shader& shader)
	{
		shader.setVec3("objectColor", color);
		shader.setMat4("model", model);
		glBindVertexArray(this->VAO);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices.size());
	}
	//Function 3
	void deleteBuffers() {
		glDeleteVertexArrays(1, &VAO);
		//glDeleteBuffers(1, &VBO);
	}


};

