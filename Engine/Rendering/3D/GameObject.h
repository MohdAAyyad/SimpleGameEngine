#ifndef GAMEOBJECT_H
#define GAMEOBJECT_h

#include "Model.h"

class GameObject
{
public:
	GameObject(Model* model_, glm::vec3 position_ = glm::vec3());
	~GameObject();
	void Render(Camera* camera_);
	void RenderInstance(Camera* camera_);
	void Update(float delatTime_);

	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;

	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);

	std::string GetTag() const;
	void SetTag(std::string tag_);
	BoundingBox GetBoundingBox();

	bool GetHit();
	void SetHit(bool hit_, int buttonType_);
	glm::mat4 GetModelInstanceTransform();
	GLuint GetShaderProgram();

private:
	std::string tag; //Used to distinguish gameobjects from each other
	Model* model;
	glm::vec3 position;
	float angle;
	glm::vec3 rotation;
	glm::vec3 scale;
	BoundingBox box;

	bool hit;

	int modelInstance; //Instead of loading multiple model objects for the multiple gameobjects that use the same model, we're gonna load the model once and have all those gameobjects use the same model, and to differentiate between them, we use an instance tracker
};

#endif // !GAMEOBJECT_H

