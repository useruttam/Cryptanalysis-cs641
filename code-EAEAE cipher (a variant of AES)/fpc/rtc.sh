#!/usr/bin/expect
log_file -a allout.log
spawn ssh student@172.27.26.188
expect  "student@172.27.26.188's password:"
send -- "cs641\r"

expect  "group name:"
send -- "team_13\r"

expect  "word:"
send -- "team_12\r"

expect  "at:"
send -- "5\r"

expect  "> "
send -- "go\r"

expect  "> "
send -- "wave\r"

expect  "> "
send -- "dive\r"

expect  "> "
send -- "go\r"

expect  "> "
send -- "read\r"

expect  "> "
send -- "password\r"

expect  "> "
send -- "c\r"

expect  "> "
send -- "vroodolwao\r"

expect  "> "
send -- "c\r"