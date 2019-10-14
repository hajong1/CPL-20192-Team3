#ifndef KNUENTITY_H
#define KNUENTITY_H

#include <GL/gl3w.h>
#include <glm/glm.hpp>

#include <vector>

namespace SYE {
	class Shader;
	struct Vertex;
}

// 다양한 Opengl class가 늘어나는 것에 대비하여 공통 변수, 함수 등을 모아둠.
class KOglBase {
	private:
	protected:
		GLuint VAO, VBO;
		glm::mat4 mMv = glm::mat4(1.0f);	//초기 위치(Model viewer matrix)
		SYE::Shader *pShader;
		std::vector<SYE::Vertex> vertices;
		void setVAO();
	public:
		KOglBase() {};
		virtual ~KOglBase() {};
};

class KOglGrid: public KOglBase {
	private:
	protected:
	public:
		KOglGrid(
				SYE::Shader *pShader
				, unsigned int rows = 10
				, unsigned int cols = 10
				, float unit = 10.0f
				, glm::mat4 mv = glm::mat4(1.0f)
				, glm::vec3 color = glm::vec3(0.7f, 0.7f, 0.7f)
				);
		virtual ~KOglGrid();
};

#endif
