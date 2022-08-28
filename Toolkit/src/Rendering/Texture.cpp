#include "Texture.h"
#include "stb_image.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace tk
{
    void Texture::Generate(const char* file)
    {
        TK_CORE_INFO("Generating texture from {}", file);
        glGenTextures(1, &index);
        glBindTexture(GL_TEXTURE_2D, index);
        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load and generate the texture
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            TK_CORE_ERROR("Failed to load texture");
        }
        stbi_image_free(data);
    }

    u32 Texture::GetIndex()
    {
        return index; 
    }

} // namespace toolkit