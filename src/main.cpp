#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>

using namespace geode::prelude;

$execute {
	using namespace keybinds;

	BindManager::get()->registerBindable({
		"toggle-pause"_spr,
		"Toggle Pause Screen",
		"Hide/Show Pause Screen",
		{ Keybind::create(KEY_H, Modifier::Control) },
		"Play"
	});
}

class $modify(PauseLayer) {
	static PauseLayer* create(bool idk) {
		PauseLayer* pause = PauseLayer::create(idk);
	
		pause->template addEventListener<keybinds::InvokeBindFilter>([=](keybinds::InvokeBindEvent* event) {
			if (event->isDown()) {
				pause->setVisible(!pause->isVisible());
			}
			
			return ListenerResult::Propagate;
		}, "toggle-pause"_spr);

		return pause;
	}
};
