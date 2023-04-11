#pragma once
#include "lve_game_object.hpp"

namespace lve
{
	class LveAnimation
	{
	public:
		LveAnimation();
		LveAnimation(LveGameObject* obj, std::vector<glm::vec3> frames);
		void calculateTransform(float delta);

	private:
		LveGameObject* gameObject;
		std::vector<glm::vec3> translationKeyFrame;
		float currentTime;
		int currentKeyframe;

		float lerp(float a, float b, float t);
		float animationLength();
	};
}