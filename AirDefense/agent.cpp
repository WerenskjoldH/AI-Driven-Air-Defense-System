#include "agent.h"
#include "keras2cpp/keras_model.h"

#include <vector>

keras::KerasModel* IntelligentAgent::model = nullptr;

void IntelligentAgent::init(std::string filePath)
{
	model = new keras::KerasModel(filePath, false);
}

float IntelligentAgent::predict(std::vector<float> vinput)
{
	keras::DataChunk2D chunk;

	std::vector<std::vector<std::vector<float>>> cinput;

	{
		std::vector<std::vector<float>> c_i_input;

		c_i_input.push_back(vinput);

		cinput.push_back(c_i_input);
	}

	chunk.set_data(cinput);

	std::vector<float> output = model->compute_output(&chunk);

	return (output.at(0) - output.at(1) + 1.f) / 2.f;
}