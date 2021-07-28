package main

import (
	"fmt"
	"os"

	"github.com/godbus/dbus"
	"github.com/godbus/dbus/introspect"
)

const intro = `
<node>
    <interface name="com.github.guelfey.Demo">
        <method name="Foo">
            <arg direction="out" type="s"/>
        </method>
    </interface>` + introspect.IntrospectDataString + `</node> `

type foo string

func (f foo) Foo() (string, *dbus.Error) {
	fmt.Println(f)
	return string(f), nil
}

func dbus_type() {

	conn, err := dbus.ConnectSessionBus()
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	f := foo("Bar!")
	conn.Export(f, "/com/github/guelfey/Demo", "com.github.guelfey.Demo")
	conn.Export(introspect.Introspectable(intro), "/com/github/guelfey/Demo",
		"org.freedesktop.DBus.Introspectable")

	reply, err := conn.RequestName("com.github.guelfey.Demo",
		dbus.NameFlagDoNotQueue)
	if err != nil {
		panic(err)
	}
	if reply != dbus.RequestNameReplyPrimaryOwner {
		fmt.Fprintln(os.Stderr, "name already taken")
		os.Exit(1)
	}
	fmt.Println("Listening on com.github.guelfey.Demo / /com/github/guelfey/Demo ...")
	select {}

}

func ExampleObject_Call() {
	conn, err := dbus.ConnectSessionBus()
	if err != nil {
		fmt.Fprintln(os.Stderr, "Failed to connect to SystemBus bus:", err)
		os.Exit(1)
	}
	defer conn.Close()

	var s int
	err = conn.Object("com.ukui.panel.desktop", "/").Call("com.ukui.panel.desktop.GetPanelSize", 0, "s").Store(&s)
	if err != nil {
		fmt.Fprintln(os.Stderr, "Failed to introspect bluez", err)
		os.Exit(1)
	}

	fmt.Println(s)
}
