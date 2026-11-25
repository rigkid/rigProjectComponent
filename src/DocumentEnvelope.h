#pragma once

/**
 * @file
 * @brief The entity whose `CProject` is this registry's document envelope.
 * @details A `.rig` file has one `document` object, so one registry has one
 * envelope entity: the entity the host passed to `bindDocument`. Readers use
 * `documentEntity` / `documentProject`. The binding lives in the registry
 * context, so it follows `MEcs::exchangeDocument` and dies with that world.
 */

#include <entt/entt.hpp>

#include "CProject.h"

namespace rigkit {
namespace project {

struct DocumentEnvelope {
	entt::entity entity{entt::null};
};

/** @brief Name @p entity as this registry's document envelope. */
inline void bindDocument(entt::registry& reg, entt::entity entity) {
	reg.ctx().emplace<DocumentEnvelope>().entity = entity;
}

/** @brief Envelope entity from `bindDocument`, or `entt::null` when unset. */
inline entt::entity documentEntity(const entt::registry& reg) {
	const auto* slot = reg.ctx().find<DocumentEnvelope>();
	return slot ? slot->entity : entt::null;
}

/** @brief `CProject` on the bound entity, or null when none is bound. */
inline ecs::CProject* documentProject(entt::registry& reg) {
	const entt::entity entity = documentEntity(reg);
	if (entity == entt::null || !reg.valid(entity) || !reg.all_of<ecs::CProject>(entity)) {
		return nullptr;
	}
	return &reg.get<ecs::CProject>(entity);
}

/** @brief `CProject` on the bound entity, or null when none is bound. */
inline const ecs::CProject* documentProject(const entt::registry& reg) {
	const entt::entity entity = documentEntity(reg);
	if (entity == entt::null || !reg.valid(entity) || !reg.all_of<ecs::CProject>(entity)) {
		return nullptr;
	}
	return &reg.get<ecs::CProject>(entity);
}

} // namespace project
} // namespace rigkit
