#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>

#include "Ray.h"
#include "Hit.h"
#include "texture.hpp"
#include "Noise.h"
class Material
{
public:

	Material( const Vector3f& d_color ,const Vector3f& s_color=Vector3f::ZERO, float s=0,
		float r =0 );

    virtual ~Material();

    virtual Vector3f getDiffuseColor() const ;

    Vector3f Shade( const Ray& ray, const Hit& hit,
            const Vector3f& dirToLight, const Vector3f& lightColor,
			const bool shadeBack ) ;

	static  Vector3f pointwiseDot( const Vector3f& v1 , const Vector3f& v2 );

	float clampedDot( const Vector3f& L , const Vector3f& N )const;
	void loadTexture(const char * filename);
	float getRefractionIndex();
	float getShininess();
	Vector3f getDiffuseColor();
	Vector3f getSpecularColor();
	Vector3f getReflectiveColor();
	Vector3f getTransparentColor();

	void setNoise(const Noise & n);
	void setReflectiveColor(const Vector3f& c);
	void setTransparentColor(const Vector3f& c);

protected:
  Vector3f diffuseColor;
  float refractionIndex;
  float shininess;
  Vector3f specularColor;
  Vector3f reflectiveColor;
  Vector3f transparentColor;
  Texture t;
  Noise noise;
};

#endif // MATERIAL_H
