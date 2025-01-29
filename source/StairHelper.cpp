#include "StairHelper.h"


const std::string PATH = "../data-files/Staircase.Scene.Any"; // Path to the scene
const float HEIGHT = 0.1;
const float ROTATION = 15;


void stairHelper() {
	G3D::TextOutput textOutput(PATH.c_str());
	textOutput.printf(
		R""""(
// -*- c++ -*-
{
	name = "Staircase";

	models = {
		stairModel = ArticulatedModel::Specification {
			filename = "model/crate/crate.obj";
			preprocess = {
				setMaterial(all(), "model/crate/woodcrate-L.png");
				transformGeometry(all(), Matrix4::scale(2, 0.1, 0.3));
			};
		};
	};

	entities = {
		skybox = Skybox{
			texture = "cubemap/noonclouds/noonclouds_*.png";
		};

		sun = Light{
			attenuation = (0, 0, 1);
			bulbPower = Power3(4e+006);
			frame = CFrame::fromXYZYPRDegrees(-15, 207, -41, -164, -77, 77);
			shadowMapSize = Vector2int16(2048, 2048);
			spotHalfAngleDegrees = 5;
			rectangular = true;
			type = "SPOT";
		};

		

		camera = Camera{
			frame = CFrame::fromXYZYPRDegrees(0, 0, 5);
		};
)""""
	);

	float y, yaw;
	for (int i = 0; i < 50; i++) {
		y = i * HEIGHT;
		yaw = i * ROTATION;
		textOutput.printf("stair%d = VisibleEntity{\n", i);
		textOutput.printf("model = stairModel;\n");
		textOutput.printf("frame = CFrame::fromXYZYPRDegrees(0, %f, 0, %f, 0, 0);\n", y, yaw);
		textOutput.printf("};\n\n");
	};

	textOutput.printf(
		R""""(
	};
};
	)""""
	);

	textOutput.commit();
};