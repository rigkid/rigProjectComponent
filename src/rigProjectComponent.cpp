#include "rigProjectComponent.h"

#include "core/RigKitEngine.h"
#include "core/pack/PackRegistry.h"
#include "ecs/MEcs.h"
#include "CPage.h"
#include "CProject.h"

#include <spdlog/spdlog.h>

namespace rigkit {

rigProjectComponent::rigProjectComponent() : IPack("rigProjectComponent") {}

bool rigProjectComponent::init() {
	spdlog::info("[rigProjectComponent] init (project data)");
	return true;
}

void rigProjectComponent::setup() {
	auto* engine = getEngine();
	if (!engine) {
		return;
	}
	if (auto* ecs = engine->getECSManager()) {
		ecs->registerComponent<ecs::CProject>("Project", true);
		ecs->registerComponent<ecs::CPage>("Page", true);
		spdlog::info("[rigProjectComponent] registered CProject/CPage");
	}
}

} // namespace rigkit

namespace {
struct rigProjectComponentRegistrar {
	rigProjectComponentRegistrar() {
		rigkit::PackRegistry::instance().addFactory("rigProjectComponent", []() {
			return std::shared_ptr<rigkit::IPack>(std::make_shared<rigkit::rigProjectComponent>());
		});
	}
};
static rigProjectComponentRegistrar rigProjectComponent_auto_reg;
} // namespace
