#include "LightForest.h"

#include "../Structures/TreeGenerator.h"

LightForest::LightForest(int seed)
  : Biome(getNoiseParameters(), 60, 80, seed) {

}

ChunkBlock LightForest::getTopBlock(Rand &rand) const {
  return BlockId::Grass;
}

ChunkBlock LightForest::getUnderWaterBlock(Rand &rand) const {
  return rand.intInRange(0, 10) > 9 ?
         BlockId::Sand :
         BlockId::Dirt;
}

void
LightForest::makeTree(Rand &rand, Chunk &chunk, int x, int y, int z) const {
  makeOakTree(chunk, rand, x, y, z);
}

NoiseParameters LightForest::getNoiseParameters() {
  // heightParams
  return NoiseParameters {
    .octaves = 5,
    .amplitude = 100,
    .smoothness = 195,
    .heightOffset = -32,
    .roughness = 0.52,
  };
}

ChunkBlock LightForest::getPlant(Rand &rand) const {
  return rand.intInRange(0, 10) > 8 ?
         BlockId::Rose :
         BlockId::TallGrass;
}
