package main

import (
	"bytes"
	"fmt"

	"github.com/spf13/viper"
)

func read_yaml() {
	viper.SetConfigType("yaml")
	var yamlExample = []byte(`
Hacker: true
name: steve
hobbies:
- skateboarding
- snowboarding
- go
clothing:
  jacket: leather
  trousers: denim
age: 35
eyes : brown
beard: true
`)
	viper.ReadConfig(bytes.NewBuffer(yamlExample))
	fmt.Println(viper.Get("name"))
}

func read_file() {
	viper.SetConfigName("config")
	viper.SetConfigType("json")
	viper.AddConfigPath("/home/sunfengsheng/test_config")
	viper.ReadInConfig()
	// err := viper.ReadInConfig()
	// if err != nil {
	// 	panic(fmt.Errorf("Fatal error config file: %w \n", err))
	// }
	fmt.Println(viper.AllKeys())
}
