#include "TextureAtlas.h"
#include <array>

TextureAtlas::TextureAtlas(const std::string &textureFileName) {
  sf::Image i;
  if (!i.loadFromFile("Res/Textures/" + textureFileName + ".png")) {
    throw std::runtime_error("Unable to open image: " + textureFileName);
  }
  loadFromImage(i);


  m_imageSize = 256;
  m_individualTextureSize = 16;
}

std::array<GLfloat, 8> TextureAtlas::getTexture(const sf::Vector2i &coords) {
  static const GLfloat TEX_PER_ROW = static_cast<GLfloat>(m_imageSize) / static_cast<GLfloat>(m_individualTextureSize);
  static const GLfloat INDV_TEX_SIZE = 1.0f / TEX_PER_ROW;
  static const GLfloat PIXEL_SIZE = 1.0f / (float) m_imageSize;

  auto xMin = static_cast<GLfloat>((coords.x * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE);
  auto yMin = static_cast<GLfloat>((coords.y * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE);

  auto xMax = static_cast<GLfloat>(xMin + INDV_TEX_SIZE - 0.5 * PIXEL_SIZE);
  auto yMax = static_cast<GLfloat>(yMin + INDV_TEX_SIZE - 0.5 * PIXEL_SIZE);

  return {
    xMax, yMax,
    xMin, yMax,
    xMin, yMin,
    xMax, yMin
  };
}
