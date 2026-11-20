#pragma once

/**
 * @file
 * @brief Print binding + paper — data only. Speaks `rig.book.binding`.
 * @details Compose on the project entity. Spine is computed by the host from
 * page count and these fields unless `hasSpineOverride` is set.
 */

#include <vector>

#include "ecs/PropertyReflection.h"

namespace rigkit {
namespace ecs {

/** @brief Binding form — order matches the RigWorks enum literals. */
enum class BookBindingForm : int {
	Paperback = 0,
	Case = 1,
	Jacket = 2,
	Saddle = 3
};

/** @brief Unit for caliper / board / hinge measures on this component. */
enum class BookCaliperUnit : int { Mm = 0, In = 1 };

/**
 * @brief Physical binding inputs for cover spine maths.
 * @details `paperCaliper` is per leaf. Fulfillment: spine =
 * pageCount/2 × paperCaliper (+ 2×boardThickness when form is Case), unless
 * `hasSpineOverride`.
 */
struct CBookBinding {
	BookBindingForm form = BookBindingForm::Paperback;
	float paperCaliper = 0.75f;
	BookCaliperUnit caliperUnit = BookCaliperUnit::Mm;
	float boardThickness = 0.f;
	float hinge = 0.f;
	float wrap = 0.f;
	float flap = 0.f;
	float fold = 0.f;
	bool hasSpineOverride = false;
	float spineOverride = 0.f;

	std::vector<sProp> GetProperties() {
		static const char* const kForm[] = {"paperback", "case", "jacket", "saddle"};
		static const char* const kUnit[] = {"mm", "in"};
		return {{0, "Form", EPT_ENUM, reinterpret_cast<int*>(&form), kForm, 4},
				{1, "Paper Caliper", EPT_FLOAT, &paperCaliper},
				{2, "Caliper Unit", EPT_ENUM, reinterpret_cast<int*>(&caliperUnit), kUnit, 2},
				{3, "Board Thickness", EPT_FLOAT, &boardThickness},
				{4, "Hinge", EPT_FLOAT, &hinge},
				{5, "Wrap", EPT_FLOAT, &wrap},
				{6, "Flap", EPT_FLOAT, &flap},
				{7, "Fold", EPT_FLOAT, &fold},
				{8, "Spine Override", EPT_BOOL, &hasSpineOverride},
				{9, "Spine Override Value", EPT_FLOAT, &spineOverride}};
	}
};

} // namespace ecs
} // namespace rigkit
