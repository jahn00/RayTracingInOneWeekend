#ifndef MATERIAL_H
#define MATERIAL_H

#include "InOneWeekend/color.h"
#include "InOneWeekend/hittable.h"
#include "InOneWeekend/ray.h"

// Material class determines how a light reflects an incident ray.
// Subclasses of Material will implement different scattering methods e.g.
// Lambertian for a matte look or Metal for a highly reflective surface.
class Material {
 public:
  virtual ~Material() = default;

  // Subclasses overriding this method will take the reflected normal vector
  // from HitResult and decide how to reflect it based on the material.
  virtual bool scatter(const Ray& incident_ray,
                       const Hittable::HitResult& result,
                       Color& attenuation,
                       Ray& scattered) const {
    return false;
  }
};

#endif