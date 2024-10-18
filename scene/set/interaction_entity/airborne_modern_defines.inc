(define "air_compact_launcher"
	{on fire "%weapon"
		("low_speed_bullet")
		{delay 0.1 {spawn "%missile_carrier" "%foresight"   x}}
		{view start "%flashbarrel"}
		{delay 0.4
			{view pause "%flashbarrel"}
		}
		{spawn "startsmoke" "%foresight" x}
	}
)
(define "air_multibarrel_launcher_generic"
	("low_speed_bullet")
	(define "fire_barrel"
		name "%0"
			{spawn "startsmoke" "%shooter%0" x}
			{delay 0.1 {spawn "%missile_carrier" "%shooter%0" x}}
			{view start "%flashbarrel%0"}
			{delay 0.4
				{view pause "%flashbarrel%0"}
			}
	)
	(define "fire_barrel_drop"
		name "%0"
			{spawn "startsmoke" "%shooter%0" x}
			{delay 0.1 {spawn "%missile_drop_carrier" "%shooter%0" x}}
			{view start "%flashbarrel%0"}
			{delay 0.4
				{view pause "%flashbarrel%0"}
			}
	)
)
(define "air_multibarrel_launcher"
	{on fire "%weapon"
		("air_multibarrel_launcher_generic" weapon(%weapon) shooter(%shooter) missile(%missile) flashbarrel(%flashbarrel))
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)
		else ("fire_barrel" args 06)
		else ("fire_barrel" args 07)
		else ("fire_barrel" args 08)
		else ("fire_barrel" args 09)
		else ("fire_barrel" args 10)
		else ("fire_barrel" args 11)
		else ("fire_barrel" args 12)
		else ("fire_barrel" args 13)
		else ("fire_barrel" args 14)
		else ("fire_barrel" args 15)
		}
		("cw_check_shooting" weap_id(%weapon))	;for single
	}
)
(define "air_multibarrel_launcher_2drop"	;missiles 1 and 2 are dropped, the rest are rail-launched
	{on fire "%weapon"
		("air_multibarrel_launcher_generic" weapon(%weapon) shooter(%shooter) missile(%missile) flashbarrel(%flashbarrel))
		{if    ("fire_barrel_drop" args 00)
		else ("fire_barrel_drop" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)
		else ("fire_barrel" args 06)
		else ("fire_barrel" args 07)
		else ("fire_barrel" args 08)
		else ("fire_barrel" args 09)
		else ("fire_barrel" args 10)
		else ("fire_barrel" args 11)
		else ("fire_barrel" args 12)
		else ("fire_barrel" args 13)
		else ("fire_barrel" args 14)
		else ("fire_barrel" args 15)
		}
		("cw_check_shooting" weap_id(%weapon))	;for single
	}
)
(define "air_multibarrel_launcher_4drop"	;missiles 1-4 are dropped, the rest are rail-launched
	{on fire "%weapon"
		("air_multibarrel_launcher_generic" weapon(%weapon) shooter(%shooter) missile(%missile) flashbarrel(%flashbarrel))
		{if    ("fire_barrel_drop" args 00)
		else ("fire_barrel_drop" args 01)
		else ("fire_barrel_drop" args 02)
		else ("fire_barrel_drop" args 03)
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)
		else ("fire_barrel" args 06)
		else ("fire_barrel" args 07)
		else ("fire_barrel" args 08)
		else ("fire_barrel" args 09)
		else ("fire_barrel" args 10)
		else ("fire_barrel" args 11)
		else ("fire_barrel" args 12)
		else ("fire_barrel" args 13)
		else ("fire_barrel" args 14)
		else ("fire_barrel" args 15)
		}
		("cw_check_shooting" weap_id(%weapon))	;for single
	}
)
(define "air_multibarrel_launcher_4drop_alt"	;missiles 3-6 are dropped, the rest are rail-launched
	{on fire "%weapon"
		("air_multibarrel_launcher_generic" weapon(%weapon) shooter(%shooter) missile(%missile) flashbarrel(%flashbarrel))
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel_drop" args 02)
		else ("fire_barrel_drop" args 03)
		else ("fire_barrel_drop" args 04)
		else ("fire_barrel_drop" args 05)
		}
		("cw_check_shooting" weap_id(%weapon))	;for single
	}
)
(define "air_multibarrel_launcher_6drop"	;missiles 1-6 are dropped, the rest are rail-launched
	{on fire "%weapon"
		("air_multibarrel_launcher_generic" weapon(%weapon) shooter(%shooter) missile(%missile) flashbarrel(%flashbarrel))
		{if    ("fire_barrel_drop" args 00)
		else ("fire_barrel_drop" args 01)
		else ("fire_barrel_drop" args 02)
		else ("fire_barrel_drop" args 03)
		else ("fire_barrel_drop" args 04)
		else ("fire_barrel_drop" args 05)
		else ("fire_barrel" args 06)
		else ("fire_barrel" args 07)
		else ("fire_barrel" args 08)
		else ("fire_barrel" args 09)
		else ("fire_barrel" args 10)
		else ("fire_barrel" args 11)
		else ("fire_barrel" args 12)
		else ("fire_barrel" args 13)
		else ("fire_barrel" args 14)
		else ("fire_barrel" args 15)
		}
		("cw_check_shooting" weap_id(%weapon))	;for single
	}
)
(define "air_nar_launcher"
	{on fire "%weapon" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{view start "%flashbarrel%0"}
				{delay 0.42
					{view pause "%flashbarrel%0"}
				}
				{spawn "startsmoke" "flashbarrel%0" x}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			else ("fire_barrel" args 20)
			else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			else ("fire_barrel" args 23)
			else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)
			else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			else ("fire_barrel" args 33)
			else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			else ("fire_barrel" args 40)
			else ("fire_barrel" args 41)
			else ("fire_barrel" args 42)
			else ("fire_barrel" args 43)
			else ("fire_barrel" args 44)
			else ("fire_barrel" args 45)
			else ("fire_barrel" args 46)
			else ("fire_barrel" args 47)
			else ("fire_barrel" args 48)
			else ("fire_barrel" args 49)
			else ("fire_barrel" args 50)
			else ("fire_barrel" args 51)
			else ("fire_barrel" args 52)
			else ("fire_barrel" args 53)
			else ("fire_barrel" args 54)
			else ("fire_barrel" args 55)
			else ("fire_barrel" args 56)
			else ("fire_barrel" args 57)
			else ("fire_barrel" args 58)
			else ("fire_barrel" args 59)
			else ("fire_barrel" args 60)
			else ("fire_barrel" args 61)
			else ("fire_barrel" args 62)
			else ("fire_barrel" args 63)
			}
	}
)
(define "air_casette_bomber"
	{on fire "%weapon" overload
		(define "fire_barrel"
			name "%0"
				{spawn "%bomb" "%bomber%0" x {impulse up 0.1 forward %speed com}}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			else ("fire_barrel" args 20)
			else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			else ("fire_barrel" args 23)
			else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)
			else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			else ("fire_barrel" args 33)
			else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
	}
)
(define "air_multibomb_launcher"
	{on fire "%weapon"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{tags remove "launch_00"}
				{tags remove "launch_01"}
				{tags remove "launch_02"}
				{tags remove "launch_03"}
				{tags remove "launch_04"}
				{tags remove "launch_05"}
				{tags remove "launch_06"}
				{tags remove "launch_07"}
				{tags remove "launch_08"}
				{tags remove "launch_09"}
				{tags remove "launch_10"}
				{tags remove "launch_11"}
				{tags remove "launch_12"}
				{tags remove "launch_13"}
				{tags remove "launch_14"}
				{tags remove "launch_15"}
				{tags add "launch_%0"}
				{delay 0.1 {spawn "%missile_%0" "%shooter%0" x}}
				{delay 2.0 {tags remove "launch_%0"}}
		)
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)
		else ("fire_barrel" args 06)
		else ("fire_barrel" args 07)
		else ("fire_barrel" args 08)
		else ("fire_barrel" args 09)
		else ("fire_barrel" args 10)
		else ("fire_barrel" args 11)
		else ("fire_barrel" args 12)
		else ("fire_barrel" args 13)
		else ("fire_barrel" args 14)
		else ("fire_barrel" args 15)
		}
		("cw_check_shooting" weap_id(%weapon))	;for single
	}
)

(define "air_gliding_bomber"
	{on fire "%weapon" overload
		(define "fire_barrel"
			name "%0"
				{spawn "%bomb" "%bomber%0" x {impulse up 0.07 forward %speed rnd_dir %spread com} {gravity 0.2}
				{delay 0.5 {impulse up -0.5 forward (* 0.07 %speed) com} {gravity 0.2}}
				{delay 1 {impulse up -0.5 forward (* 0.08 %speed) com} {gravity 0.3}}
				{delay 1.5 {impulse up -0.5 forward (* 0.09 %speed) com} {gravity 0.3}}
				{delay 2 {impulse up -0.5 forward (* 0.09 %speed) com} {gravity 0.3}}
				{delay 2.5 {impulse up -1 forward (* 0.10 %speed) com} {gravity 0.4}}
				{delay 3 {impulse up -1 forward (* 0.10 %speed) com} {gravity 0.4}}
				{delay 3.5 {impulse up -1 forward (* 0.10 %speed) com} {gravity 0.4}}
				{delay 4 {impulse up -1 forward (* 0.10 %speed) com} {gravity 0.5}}
				{delay 4.5 {impulse up -1 forward (* 0.11 %speed) com} {gravity 0.5}}
				{delay 5 {impulse up -1 forward (* 0.11 %speed) com} {gravity 0.6}}
				{delay 5.5 {impulse up -1 forward (* 0.11 %speed) com} {gravity 0.6}}
				{delay 6 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 7 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 7.5 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 8 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 8.5 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 9 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 9.5 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 10 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				{delay 10.5 {impulse up -1.5 forward (* 0.11 %speed) com} {gravity 0.7}}
				}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			else ("fire_barrel" args 20)
			else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			else ("fire_barrel" args 23)
			else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)
			else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			else ("fire_barrel" args 33)
			else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
	}
)

(define "single_alt_control"
	(define "remove_alt_tags"
		{tags remove "alt_47"}
		{tags remove "alt_40"}
		{tags remove "alt_32"}
		{tags remove "alt_25"}
		{tags remove "alt_17"}
		{tags remove "alt_10"}
	
	)
	{on "update_lights"
		{if tagged "single_check_alt"	;water level below zero on -200
			("remove_alt_tags")
			{if altitude 54 {tags add "alt_47"}
			else altitude 46 {tags add "alt_40"}
			else altitude 38 {tags add "alt_32"}
			else altitude 31 {tags add "alt_25"}
			else altitude 23 {tags add "alt_17"}
			else altitude 15 {tags add "alt_10"}
			}
		}
	}
)