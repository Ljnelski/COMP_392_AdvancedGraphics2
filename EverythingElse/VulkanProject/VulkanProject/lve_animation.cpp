#include "lve_animation.hpp"
#include <iostream>

namespace lve
{
	LveAnimation::LveAnimation()
	{
		gameObject = nullptr;
		currentTime = 0;
		currentKeyframe = 0;
	}

	LveAnimation::LveAnimation(LveGameObject* obj, std::vector<glm::vec3> frames) 
		: gameObject{ obj }, translationKeyFrame{frames}
	{
		currentTime = 0;
		currentKeyframe = 0;
	}

	void LveAnimation::calculateTransform(float delta)
	{
		currentTime += delta;
		if (currentTime > static_cast<float>(currentKeyframe))
		{
			currentKeyframe = (currentKeyframe + 1) % translationKeyFrame.size();
		}
		std::cout << "currentKeyFrameIndex: " << currentKeyframe << "\n";
		gameObject->transform.translation = translationKeyFrame[currentKeyframe];
		//std::cout << "Y component: " << gameObject->transform.translation.y << "\n";
		//std::cout << "Y component: " << gameObject->transform.translation. << "\n";
	}

	float LveAnimation::lerp(float a, float b, float t)
	{
		return (1 - t) * a + t * b;
	}

	float LveAnimation::animationLength()
	{
		return static_cast<float>(translationKeyFrame.size());
	}
}