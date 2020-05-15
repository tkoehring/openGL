#ifndef SHADER_H
#define SHADER_H

#include "graphics_headers.h"
#include <string>

class Shader
{
	private:
        //Parameters
		unsigned int id;
        bool compiled;
        const char *vs_path, *fs_path;

		//Methods
		void loadSource(const char*, int);
        bool compile(int, int);

	public:
        //Methods
		Shader(const char*, const char*);
		unsigned int getID() const {return id;};
		void activate() const;
		void setBool(const std::string&, bool val) const;
        void setInt(const std::string&, int val) const;
        void setFloat(const std::string&, float val) const;
        void setDouble(const std::string&, double val) const;
        void setVec2f(const std::string&, glm::vec2) const;
        void setVec3f(const std::string&, glm::vec3) const;
        void setVec4f(const std::string&, glm::vec4) const;
        void setMat2f(const std::string&, glm::mat2) const;
        void setMat3f(const std::string&, glm::mat3) const;
        void setMat4f(const std::string&, glm::mat4) const;
};
#endif