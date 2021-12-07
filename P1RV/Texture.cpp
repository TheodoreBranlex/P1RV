#include <glut.h>
#include "stb_image.h"
#include "Texture.h"


Texture::Texture(const char* path)
{
	data = stbi_load(path, &width, &height, &channels, 0);
}

void Texture::Use()
{
	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glEnable(GL_TEXTURE_2D);
}