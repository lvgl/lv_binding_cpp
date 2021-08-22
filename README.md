# lv_binding_cpp
[WIP] C++ binding for LVGL

# Description
The Wrapper simplify the creation of Widgets and initialization of the library. It integrate the feature of library initialization, Display initialization , Input Initialization and Thick initialization based on periodic Thread. 
For this manners every application should inherit from the base class "LvApp" and perform widgets initialization.
At moment works on Linux in a early stage.
We have to create some cross platform implementation.

# Usage

You can simply create widgets in this way:


```cpp
/* Button */
HelloButton = Make<LvBtn>();
HelloButton->setSize(200, 100).
			setX(0).
			align(LV_ALIGN_CENTER,0,0);
```

# Example

This is a simple example of LvApplication.

```cpp

class HelloEx: public LvApp {
private:

	/* Some Widgets declaration */
	LvPPointer<LvBtn> HelloButton;
	LvPPointer<LvLabel> HelloLabel;
	LvPPointer<LvTabview> view;

	/* Callbacks */
	LvEventPointer<HelloEx> Hello;
	LvEventPointer<HelloEx> HelloLong;

	void Hello_cb(lv_event_t* e);
	void HelloLong_cb(lv_event_t* e);

	/* The Application */
	int AppInit();
	void AppBody();
	void AppExit();

public:
	HelloEx();
	virtual ~HelloEx();
};



/***************************************************** The Application ******************************************************/
int HelloEx::AppInit() {

	/* Enable Cursor */
	Io->enableCursor();

	/* Tabview */
	view = Make<LvTabview>();
	LvObj& firstTab = view->addTab("Controls");
	view->addTab("Yep");
	view->addTab("Wahooo");

	/* Button */
	HelloButton = Make<LvBtn>(&firstTab);
	HelloButton->setSize(200, 100).
			setX(0).
			align(LV_ALIGN_CENTER,0,0);

	/* Creating a new callback and register to the object */
	Hello = Make<LvEventCb<HelloEx>>(&HelloEx::Hello_cb,this);
	HelloLong = Make<LvEventCb<HelloEx>>(&HelloEx::HelloLong_cb,this);
	HelloButton->setCallback(LV_EVENT_PRESSED, Hello.get());
	HelloButton->setCallback(LV_EVENT_LONG_PRESSED, HelloLong.get());

	/* Button Label */
	HelloLabel = Make<LvLabel>(HelloButton.get());
	HelloLabel->setTextFmt("Hello %s", "fstuff-dev").
			align(LV_ALIGN_CENTER, 0,0);


	return 0;
}

void HelloEx::AppBody() {

}

void HelloEx::AppExit() {

}

/* Callbacks */
void HelloEx::Hello_cb(lv_event_t* e) {

	/* HelloLabel is part of the class so you're able to directly access it */
	HelloLabel->setText("Pressed");
	printf("Pressed Callback !!! \n");
}

/* Callbacks */
void HelloEx::HelloLong_cb(lv_event_t* e) {

	/* HelloLabel is part of the class so you're able to directly access it */
	HelloLabel->setText("LongPressed");
	printf("LongPressed Callback !!! \n");
}

```

The Application should implement this three virtual methods:

```cpp

	/* The Application */
	int AppInit();
	void AppBody();
	void AppExit();

```

"AppInit()" is called once at initialization.
"AppBody" is called periodically every "x" ms. Where "x" is set at LvApp Object construction.
"AppExit" is called at Application end.

This is a typical main implementation

```cpp
int main (int argc,char** argv) {
	
	/* Creating LvApp Derived class Object */
	HelloEx App;
	/* Start the App */
	App.Go();
	/* Join the App Thread */
	App.Jo();

	return 0;
}
```



