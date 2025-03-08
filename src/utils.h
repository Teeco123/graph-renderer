float SmoothingKernel(float radius, float dst) {

  float squared = radius * radius - dst * dst;
  float value = (0 < squared) ? squared : 0;

  return value * value * value;
}
