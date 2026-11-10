#pragma once

#include "core/pack/IPack.h"
namespace rigkit {

/**
 * @brief Data pack - project envelope PODs (`CProject`, `CPage`). No IO.
 * @details Document read/write, the `.rig` codecs, and the deferred
 * load/save system live in the `rigProject` code pack.
 */
class rigProjectComponent : public IPack {
  public:
	rigProjectComponent();
	bool init() override;
	void setup() override;
};

} // namespace rigkit
