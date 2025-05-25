#Requires AutoHotkey v2.0

;macro workaround for 60% keybaord
;to write slash
CapsLock & Up::/
;delete workaround for my keybaord
CapsLock & Backspace::Delete

;all keys instead of ctrl+a 
CapsLock & a::Send "^a"


;disable caps lock unless you want it to
;press shift + capslock will make caps do regular caps things
CapsLock::return

;old linux habits never die
LControl  & e::Send "{End}"
LControl  & a::Send "{Home}"
;vim shortcuts
LControl & f::Send "{PgDn}"
LControl & b::Send "{PgUp}"
;replace traditional find with caps 
CapsLock & f::Send "^f"
CapsLock & Esc::Suspend
;^w::Send("^+{Left}{Backspace}")

;regular F keys down here
CapsLock & 1::F1
CapsLock & 2::F2
CapsLock & 3::F3
CapsLock & 4::F4
CapsLock & 5::F5
CapsLock & 6::F6
CapsLock & 7::F7
CapsLock & 8::F8
CapsLock & 9::F9
CapsLock & 0::F10
CapsLock & -::F11
CapsLock & =::F12


;Custom arrow keys here as well
CapsLock & i::Up
CapsLock & k::Down
CapsLock & j::Left
CapsLock & l::Right

;useful function keys here as well,
LAlt & 0::Send "{Volume_Mute}"
LAlt & -::Send "{Volume_Up}" 
LAlt & =::Send "{Volume_Down}"

;this one is just alt f4 but just alt 4
LAlt & 4::Send("{Alt down}{F4}{Alt up}")