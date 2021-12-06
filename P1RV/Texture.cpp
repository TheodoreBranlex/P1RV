#include <glut.h>
#include "stb_image.h"
#include "Texture.h"


Texture::Texture(const char* path)
{
	data = stbi_load(path, &width, &height, &channels, 0);
}