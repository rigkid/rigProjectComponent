#pragma once

/**
 * @file
 * @brief Publishing extent — data only. Speaks a slice of `rig.book.publication`.
 * @details Hosts may attach the full publication schema later; pageCount drives
 * cover spine maths with `CBookBinding`.
 */

#include <vector>

#include "ecs/PropertyReflection.h"

namespace rigkit {
namespace ecs {

/**
 * @brief Minimal publication fields needed for binding / cover.
 * @details `pageCount` 0 means unset — hosts fall back to document page count.
 */
struct CBookPublication {
	unsigned pageCount = 0;
	/// 0 hardcover, 1 paperback, 2 ebook, 3 audiobook, 4 other (publication enum).
	int productForm = 1;

	std::vector<sProp> GetProperties() {
		static const char* const kForm[] = {"hardcover", "paperback", "ebook", "audiobook",
											"other"};
		return {{0, "Page Count", EPT_UINT, &pageCount},
				{1, "Product Form", EPT_ENUM, &productForm, kForm, 5}};
	}
};

} // namespace ecs
} // namespace rigkit
