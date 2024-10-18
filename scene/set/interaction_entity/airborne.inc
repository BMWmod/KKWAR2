;common defines for heli and planes

{"airborne"
;	{friction 0.2}
;	{restitution 0.01}
;//////////////////////VRT System by Pheonix 1.0\\\\\\\\\\\\\\\\\\


;	(define "burn_part"
;		{on "burn_%0_start"
;			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_1"}
;			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_2"}
;			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_3"}
;			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_1"}
;			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_2"}
;			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_3"}
;			{view start "fire%0"}
;		}
;		{on "burn_%0_stop"
;			{view stop "fire%0"}
;		}
;	)
;	("burn_part" args 1)
;	("burn_part" args 2)
;	("burn_part" args 3)
;	("burn_part" args 4)

	{on "die"
		{chassis_work 0}
		{drop_orders}
		{call "engine_stop"}
		{stop_sound "fall"}
		{stop_sound "engine_stop"}
		{explosive 0}
		{burn stop}
		{bone hide "engine_work"}
		{tags add "destroyed"}
	}
	{on "smokescreen" overload
	  {if operatable
		{call "cwsh_switch_hatch"}
	 }	
	}
}

{"airborne no_explosion"
	{on contact
;		{components "wingleft" destroy}
;		{components "wingright" destroy}
	}
	{on ground_hit
		{call "die"}
		{impulse up 0.1 com}
	}
	{on "_explosion" overload
		{call "die"}
		{impulse up 0.1 com}
		("cut_part" args "wingr2"		0.5)
		("cut_part" args "wingl2"		0.5)
	}
	{on "fall_fx" overload
	}
}

{"air_part"
	{on spawn
		{delay 0.1
			{volumes enable contact contact_ground}
		}
		{view stop ""}
		{add_view "smoke_black" "smoke" "root"}
		{view start "smoke"}
		{delay 180 30
			{view stop "smoke"}
		}
	}
	{on ground_hit
		{if min_speed 5
			{spawn "spheredust_big_short"}
		}
	}
}

{"air_part wing"
	{on ground_hit
		{if volume "part"
			{if volume_bone_level 3
				{call "tear_part"}
			}
		}
	}
	{on "tear_part"
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 0.1 0.05}
		}
	}
}

(include "helicopter_m.inc")
(include "missile_m.inc")