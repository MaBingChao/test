#!/bin/bash
name= abcd

files=$(foreach tmp,$(name),$(tmp).o)

