#ifndef AGENT_H
#define AGENT_H

#include <vector>

#include "keras2cpp/keras_model.h"

class IntelligentAgent
{
public:
	static void init(std::string filePath);

	static float predict(std::vector<float> vinput);

private:
	static keras::KerasModel* model;
};

#endif