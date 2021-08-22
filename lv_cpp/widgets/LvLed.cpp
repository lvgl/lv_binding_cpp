/*
 * LvLed.cpp
 *
 */

#include "LvLed.h"

namespace lvglpp {

LvLed::LvLed() : LvLed(NULL) {
}

LvLed::LvLed(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_led_create(Parent->raw()));
	else
		cObj.reset(lv_led_create(lv_scr_act()));

	setUserData(this);
}

LvLed::~LvLed() {
}
LvLed& LvLed::setColor(lv_color_t color){
	lv_led_set_color(cObj.get(),color);
	return *this;
}
LvLed& LvLed::setBrightness(uint8_t bright){
	lv_led_set_brightness(cObj.get(),bright);
	return *this;
}
LvLed& LvLed::on(){
	lv_led_on(cObj.get());
	return *this;
}
LvLed& LvLed::off(){
	lv_led_off(cObj.get());
	return *this;
}
LvLed& LvLed::toggle(){
	lv_led_toggle(cObj.get());
	return *this;
}
uint8_t LvLed::getBrightness() const noexcept {
	return lv_led_get_brightness(cObj.get());
	
}

} /* namespace lvglpp */
