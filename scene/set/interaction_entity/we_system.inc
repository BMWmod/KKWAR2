;WE System by Pheonix
(include "/lists/missile_settings3.inc")

{on "link_weapon"	
	{if effector "stuff weapon"
		{with_effector
			{call "link"}
		}
	}
	{if stuff "low_speed"
		{tags add "low_speed_weapon"}
	else
		{tags remove "low_speed_weapon"}
	}
	{if stuff "radar"
	else stuff "weapon rifle"
		{add_view "zenit_gilz" "shell" "FXshell"}
		{if not stuff "sd" 	{add_view "flash_gun_big" "flashbarrel" "foresight3"}}
;		{add_view "we_smoke" "smoke_or" "foresight3"}
	else stuff "weapon smg"
		{add_view "smg_gilz" "shell" "FXshell"}
		{if not stuff "sd" 	{add_view "flash_gun_small" "flashbarrel" "foresight3"}}
;		{add_view "we_smoke" "smoke_or" "foresight3"}
	else stuff "weapon mgun"
		{add_view "smg_gilz" "shell" "FXshell"}
		{if not stuff "sd" 	{add_view "flash_gun_big" "flashbarrel" "foresight3"}}
;		{add_view "we_smoke" "smoke_or" "foresight3"}
	else stuff "weapon gra_launch"
		{if not stuff "sd" 	{add_view "startsm_grl" "flashbarrel" "foresight3"}}
;		{add_view "we_smoke" "smoke_or" "foresight3"}
	else stuff "weapon rocketlauncher"
		{add_view "flash_bazooka" "flashbarrel" "foresight3"}
	else stuff "weapon shotgun"
		{add_view "zenit_gilz" "shell" "FXshell"}
		{if not stuff "sd" 	{add_view "flash_shotgun" "flashbarrel" "foresight3"}}
;		{add_view "we_smoke" "smoke_or" "foresight3"}
	else stuff "laser_designator"
		(mod not "mp" {add_view "laser_designator" "laser_designator" "foresight3"})
		{view hide "laser_designator"}
	else stuff "weapon pistol"
		{add_view "smg_gilz" "shell" "FXshell"}
		{if not stuff "sd" 	{add_view "flash_gun_small" "flashbarrel" "foresight3"}}
;		{add_view "we_smoke" "smoke_or" "foresight3"}
	else stuff "flame_thrower_pyro"
		{add_view "flamer_fire" "flame_pyro" "foresight3"}
		("jet_of_fire_sound_init" name(human))
	else stuff "flame_thrower"
		{add_view "flamer_fire" "flame" "foresight3"}
		{add_view "flamer_fire_barrel" "fire" "foresight3"}
		{view show	"fire"}
		{view start	"fire"}
		("jet_of_fire_sound_init" name(human))
	else
		{view hide	"flashbarrel"}
		{view hide	"laser"}
		{view pause	"laser"}
		{view hide	"light"}
		{view pause	"flashbarrel"}
		{view pause	"flame"}
		{view pause	"flame_pyro"}
		{view stop	"bullet"}
		{view pause	"flash_fire"}
	}
	{if stuff "weapon lg"
		{add_view "laser_day" "laser1" "foresight3"}
	else stuff "weapon lgs"
		{add_view "laser_day" "laser1" "foresight3"}
	}
	{if stuff "fn"
		{add_view 	"weap_light"		"light"	"foresight3"}	
		{add_view 	"weap_light_spot"	"light"			"foresight3"}
		{view stop "light"}
		{view hide "light"}
	}
	(include "/lists/handheld_atgms.inc")
	("list_handheld_atgms_link")
;=======================================misfires
{set "reliability_low" 0}
{set "reliability_medium" 0}
{set "reliability_high" 0}
{if stuff "reliability_low"
	{set "reliability_low" 1}
else stuff "reliability_medium"
	{set "reliability_medium" 1}
else stuff "reliability_high"
	{set "reliability_high" 1}
}
{if stuff "not_for_human" {weapon_work "hand_right" 0}
else {weapon_work "hand_right" 1}}
;=======================================misfires
}
{on "start_update_lights"
	{call "update_lights"}
	{if not dead {delay 30 8 "update_lights" {call "start_update_lights"}}}
}
{on "update_lights"
		{if sunlight or attacked or under_fire or dead or dying or distance_to_frontline_less_than 50
				{view stop "light"}
				{view hide "light"}
				{view pause "light"}
			else not dead and not dying
				{view start "light"}
				{view show "light"}
		}
}
{on fire "hand_right"
;		{if effector "stuff weapon"
;			{with_effector
;				{call "fire"}
;			}
;		}
		("blast")
;		{with_effector
;			{ani_play "recoil"}
;		}
	{if tagged "cw_check_shooting_once"
		{tags add "cw_i_am_shooting"}
		{kill_delay "cw_shooting"}
		{delay 3 "cw_shooting"
			{tags remove  "cw_i_am_shooting"}
			{tags remove  "cw_check_shooting_once"}
		}
	else tagged "cw_check_shooting"
		{tags add "cw_i_am_shooting"}
		{kill_delay "cw_shooting"}
		{delay 3 "cw_shooting"
			{tags remove  "cw_i_am_shooting"}
		}
	}
	
	(include "/lists/handheld_atgms.inc")
	("list_handheld_atgms_fire")


;======KAZ system part
	{if tagged "low_speed_weapon"
	{tags add "low_speed_bullet"}
	{delay 0.5 {tags remove "low_speed_bullet"}}
	}
;======
	{view show "laser_designator"}
	{delay 0.6
		{view hide "laser_designator"}
	}
	{view show	"flashbarrel"}
	{view start	"flashbarrel"}

;	{view show	"smoke_or"}
;	{view start	"smoke_or"}
	{view show	"shells_we"}
	{view start	"shells_we"}
	{view show	"shell"}
	{view start	"shell"}

	{view start	"flame"}
	{view start	"flame_pyro"}
	("jet_of_fire_sound_play" name(human) loop_fade_in(0.1))
	("jet_of_fire_sound_stop" name(human) loop_fade_out(0.1))
	{view start	"bullet"}
	{view start	"smoke_body"}

	{kill_delay "fire"}
	{kill_delay "shells_we"}
	{delay 0.2
		{view pause	"shells_we"}
		{view pause	"shell"}
	}
	{delay 0.45 "fire"
		{view hide	"flashbarrel"}
		{view pause	"flashbarrel"}
		{view pause	"smoke_or"}
		{view hide	"smoke_or"}

		{view pause	"flashbarrell"}
		{view pause	"smoke_body"}
		{view pause	"flame"}
		{view pause	"bullet"}
	}
	{delay 2 "fire"
		{view pause	"flame_pyro"}
	}
	{spawn "bazooka_shot" "fxshot" x}

;=======================================misfires
(define "misfire_check"
	{if terrain_fx "%terrain"
	     {if rand %terrain_coeff 
		{if lying
		      {if not rain
			{call "misfire"}
		      else
			{if rand %rain_coeff 
				{call "misfire"}
			}
		     }
		else rand %stand_coeff
		      {if not rain
			{call "misfire"}
		      else
			{if rand %rain_coeff 
				{call "misfire"}
			}
		     }
		}
	     }
	}
)

;("misfire_check" terrain(sand) terrain_coeff(1) rain_coeff(0.7) stand_coeff(0.7))
;terrain(sand) - на какой почве проверка
;terrain_coeff(1) - общее влияние почвы. Песок, пыль, вода ухудшают надежность оружия.
;	Чем больше - тем выше вероятность осечки. Номинальная - 0,33
;rain_coeff(0.7) - влияние дождя. Дождь не ухудшает надежность оружия, но снижает количество пыли.
;	1 - дождь не влияет, чем меньше, тем меньше осечек в дождь. Тяжелые частицы (песок) прибиваются хуже легких (пыль)
;stand_coeff(0.7) Ползая, оружие загрязнить легче. Тяжелые частицы (песок) более опасны внизу, легкие (пыль) загрязнят оружие и стоя.
;	1 - не влияет. Чем меньше, тем меньше осечек не лежа.

	{if rand 0.015	;ненадежные винтовки дают около 1,5% осечек (М16 - 882 на 60 000 выстрелов)
			;в условиях максимального загрязнения, terrain_coeff(1).
			;На малопыльной земле осечек больше, поэтому 0,015
		{if flag "reliability_low"
			("misfire_check" terrain(road) 	terrain_coeff(0.4) rain_coeff(0.9) stand_coeff(1))
			("misfire_check" terrain(country_road) terrain_coeff(0.66) rain_coeff(0.7) stand_coeff(0.7))
			("misfire_check" terrain(ice) 		terrain_coeff(0.4) rain_coeff(1) stand_coeff(0.9))
			("misfire_check" terrain(snow) 	terrain_coeff(0.4) rain_coeff(1) stand_coeff(0.9))
			("misfire_check" terrain(sand) 	terrain_coeff(1) rain_coeff(0.9) stand_coeff(0.36))
			("misfire_check" terrain(grass) 	terrain_coeff(0.5) rain_coeff(1) stand_coeff(0.6))
			("misfire_check" terrain(ground) 	terrain_coeff(0.66) rain_coeff(0.9) stand_coeff(0.6))
			("misfire_check" terrain(bridge) 	terrain_coeff(0.4) rain_coeff(0.9) stand_coeff(1))
			("misfire_check" terrain(bridge_wood) terrain_coeff(0.33) rain_coeff(1) stand_coeff(1))
			("misfire_check" terrain(water) 	terrain_coeff(0.9) rain_coeff(1) stand_coeff(0.3))
			("misfire_check" terrain(swamp) 	terrain_coeff(1) rain_coeff(1) stand_coeff(0.3))
		}
		{if rand 0.2	;средней надежности дают  около 0,3%, то есть впятеро меньше ненадежных (G36 233 на 60 000)
			{if flag "reliability_medium"
				("misfire_check" terrain(road) 	terrain_coeff(0.4) rain_coeff(0.9) stand_coeff(1))
				("misfire_check" terrain(country_road) terrain_coeff(0.66) rain_coeff(0.7) stand_coeff(0.7))
				("misfire_check" terrain(ice) 		terrain_coeff(0.4) rain_coeff(1) stand_coeff(0.9))
				("misfire_check" terrain(snow) 	terrain_coeff(0.4) rain_coeff(1) stand_coeff(0.9))
				("misfire_check" terrain(sand) 	terrain_coeff(1) rain_coeff(0.9) stand_coeff(0.36))
				("misfire_check" terrain(grass) 	terrain_coeff(0.5) rain_coeff(1) stand_coeff(0.6))
				("misfire_check" terrain(ground) 	terrain_coeff(0.66) rain_coeff(0.9) stand_coeff(0.6))
				("misfire_check" terrain(bridge) 	terrain_coeff(0.4) rain_coeff(0.9) stand_coeff(1))
				("misfire_check" terrain(bridge_wood) terrain_coeff(0.33) rain_coeff(1) stand_coeff(1))
				("misfire_check" terrain(water) 	terrain_coeff(0.9) rain_coeff(1) stand_coeff(0.3))
				("misfire_check" terrain(swamp) 	terrain_coeff(1) rain_coeff(1) stand_coeff(0.3))
			}
			{if rand 0.33	;надежные дают  около 0,10%, то есть втрое меньше средней надежности (0,015*0,2*0,33=0,05%) (Ак-47)

			{if flag "reliability_high"
					("misfire_check" terrain(road) 	terrain_coeff(0.4) rain_coeff(0.9) stand_coeff(1))
					("misfire_check" terrain(country_road) terrain_coeff(0.66) rain_coeff(0.7) stand_coeff(0.7))
					("misfire_check" terrain(ice) 		terrain_coeff(0.4) rain_coeff(1) stand_coeff(0.9))
					("misfire_check" terrain(snow) 	terrain_coeff(0.4) rain_coeff(1) stand_coeff(0.9))
					("misfire_check" terrain(sand) 	terrain_coeff(1) rain_coeff(0.9) stand_coeff(0.36))
					("misfire_check" terrain(grass) 	terrain_coeff(0.5) rain_coeff(1) stand_coeff(0.6))	
					("misfire_check" terrain(ground) 	terrain_coeff(0.66) rain_coeff(0.9) stand_coeff(0.6))
					("misfire_check" terrain(bridge) 	terrain_coeff(0.4) rain_coeff(0.9) stand_coeff(1))
					("misfire_check" terrain(bridge_wood) terrain_coeff(0.33) rain_coeff(1) stand_coeff(1))
					("misfire_check" terrain(water) 	terrain_coeff(0.9) rain_coeff(1) stand_coeff(0.3))
					("misfire_check" terrain(swamp) 	terrain_coeff(1) rain_coeff(1) stand_coeff(0.3))
				}
	    		 }
		}
	}
}
;=======================================misfires
{on "misfire"
	{start_sound "weapon/special/ak_empty"}
	{weapon_work "hand_right" 0}
	{damage_report "head" "misfire"}		
	{if flag "reliability_high"
		{delay 3 
			{weapon_work "hand_right" 1}
		}
	else flag "reliability_medium"
		{if rand 0.5
			{delay 2.5 
				{weapon_work "hand_right" 1}
			}
		else
			{delay 5
				{weapon_work "hand_right" 1}
			}
		}
	else flag "reliability_low"
		{if rand 0.3
			{delay 3 
				{weapon_work "hand_right" 1}
			}
		else  rand 0.6
			{delay 6
				{weapon_work "hand_right" 1}
			}
		else
			{delay 9
				{weapon_work "hand_right" 1}
			}	
		}
	}
}
;=======================================misfires