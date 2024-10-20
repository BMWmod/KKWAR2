{"a-10c"
	{on "link_engine_effects" overload
		{add_view	"turbovent_exhaust"	"engine1_exhaust"		"engine1_exhaust"	}
		{add_view	"turbovent_exhaust"	"engine2_exhaust" 		"engine2_exhaust"	}
		{add_view	"turbovent_overburn"		"engine1_overburn"		"engine1_exhaust"	}
		{add_view	"turbovent_overburn"		"engine2_overburn" 		"engine2_exhaust"	}
			("link_damage_sound_usa")
	}
	{on "tear_part" 
		{if volume "part9" {components "engine1" destroy}
		else volume "part10" {components "engine2" destroy}}
		{if component "elevator_l" {components "ecm" destroy}}
	}
	{on "u_w_hydrosystem_damaged"
		{weapon_work "gun" 0}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur" 0}
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur" 0}
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
	}
	{on fire "gun"
		{spawn "tank_canon_fire_small" "foresight1" x}
	}
}

{"a-10c_support"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel4"			"Foresight4"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
		{add_view	"flash_cannon_big"		"flashbarrel5"			"aim-9l_shooter"}

		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter18"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "bomber" 0}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "bomber" 0}
	}
	("air_compact_launcher" weapon(ptur1) missile(agm-65g) foresight(Foresight3) flashbarrel(flashbarrel3))
	("air_compact_launcher" weapon(ptur2) missile(agm-65d) foresight(Foresight4) flashbarrel(flashbarrel4))
	("air_compact_launcher" weapon(ptur3) missile(aim-9l) foresight(aim-9l_shooter) flashbarrel(flashbarrel5))
	("air_nar_launcher" weapon(nar1) flashbarrel(rok_tail))
}

{"a-10c_AT"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel4"			"Foresight4"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
		{add_view	"flash_cannon_big"		"flashbarrel5"			"aim-9l_shooter"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "bomber" 0}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "bomber" 0}
	}
	("air_gliding_bomber" weapon(bomber1) bomb(cbu-97_impactor) bomber(bomber1_) speed(28) gravity(0.3) spread(5))
	("air_compact_launcher" weapon(ptur1) missile(agm-65d) foresight(foresight3) flashbarrel(flashbarrel3))
	("air_compact_launcher" weapon(ptur2) missile(agm-65d) foresight(foresight4) flashbarrel(flashbarrel4))
	("air_compact_launcher" weapon(ptur3) missile(aim-9l) foresight(aim-9l_shooter) flashbarrel(flashbarrel5))
}

{"a-10c_bomber"
}

{"su-25sm"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view	"flash_cannon_big"		"R60_00"			"R60_00"}
		{add_view	"flash_cannon_big"		"R60_01"			"R60_01"}
	}
	{on "link_engine_effects" overload
		{add_view	"airstream_exhaust"	"engine1_exhaust"		"engine1_exhaust"	}
		{add_view	"airstream_exhaust"	"engine2_exhaust" 		"engine2_exhaust"	}
		{add_view	"turbovent_overburn"		"engine1_overburn"		"engine1_exhaust"	}
		{add_view	"turbovent_overburn"		"engine2_overburn" 		"engine2_exhaust"	}
			("link_damage_sound_rus")
	}
	{on "fall"
		{volumes "fuel_tank_internal_b_vol" disable all}
		{volumes "fuel_tank_internal_c_vol" disable all}
	}
	{on "scripted_fillipov"
		{spawn "tank_die_particle"}
		{burn volume "engine2" fx "smoke_black" fake}
		("stop_damage_sound")
		{play_sound "engine2_damage"}
		{view start "engine2_smoke"}
		{delay 2
			{add_view "smoke_dead_norm" "burn_fire2" "engine2_exhaust"}
			{add_view "smoke_black" "burn_fire2" "engine2_exhaust"}
			{view start "burn_fire2"}
			{play_sound "flame" 1}
		}
		{delay 7
			{play_sound "engine1_damage"}
			{view start "engine1_smoke"}
			{burn volume "engine1" fx "smoke_black" fake}
			{add_view "smoke_dead_norm" "burn_fire1" "engine1_exhaust"}
			{add_view "smoke_black" "burn_fire1" "engine1_exhaust"}
			{view start "burn_fire1"}
			{play_sound "flame" 1}
		}
	}
}

{"su-25sm_support"
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur1" 0}
		{tags add "no_missile_control"}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
	}
	("air_multibarrel_launcher" weapon(ptur1) shooter(X-25_shooter_) missile(x_25ml_su25_ammo) flashbarrel(X-25_shooter_))
	("air_multibarrel_launcher" weapon(ptur2) shooter(R60_) missile(r60_su25) flashbarrel(R60_))
	("air_nar_launcher" weapon(nar1) flashbarrel(B8shooter_))
	("air_gliding_bomber" weapon(bomber) bomb(rbk_250_impactor) bomber(RBK250_) speed(35) spread(5))
}
{"su-25sm_support_light"
	
	("air_multibarrel_launcher" weapon(ptur2) shooter(Shooter_r73rvvsd_) missile(r-73) flashbarrel(Shooter_r73rvvsd_))
	("air_nar_launcher" weapon(nar1) flashbarrel(B8shooter_))
	{on fire "nar1_s13"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{view start "tailL%0"}
				{delay 0.42
					{view pause "tailL%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			}
	}
	{on fire "nar2_s13"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{view start "tailR%0"}
				{delay 0.42
					{view pause "tailR%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			}
	}
)
}
{"su-25sm_accurate"
	{on spawn 
		{add_view	 	"BMP2_canon_fire"	"flashbarrel1"		"Foresight1"}
		{add_view	"flash_cannon_big"		"X-25_shooter_00"			"X-25_shooter_00"}
		{add_view	"flash_cannon_big"		"X-25_shooter_01"			"X-25_shooter_01"}
		{add_view	"flash_cannon_big"		"R60_00"			"R60_00"}
		{add_view	"flash_cannon_big"		"R60_01"			"R60_01"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "nar1" 0}
		{tags add "no_missile_control"}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
		{weapon_work "nar1" 0}
	}
	("air_multibarrel_launcher" weapon(ptur1) shooter(X-25_shooter_) missile(x_25ml_su25_ammo) flashbarrel(X-25_shooter_))
	("air_multibarrel_launcher" weapon(ptur2) shooter(R60_) missile(r60_su25) flashbarrel(R60_))
	{on fire "nar1"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "C-25_shooter_%0" x}
				{spawn "startsmoke" "C-25_tail_%0" x}
		)
		{if    ("fire_barrel" args 00) else ("fire_barrel" args 01) else ("fire_barrel" args 02)
			else ("fire_barrel" args 03) else ("fire_barrel" args 04) else ("fire_barrel" args 05)
		}
	}
}

{"su-25sm_miner"
	{on spawn 
		{add_view	 	"BMP2_canon_fire"	"flashbarrel1"		"Foresight1"}
		{link_sound "kmgu_shoot"	"weapon/shot/reactive/Flare"}
		{link_sound "kmgu_open"	"vehicle/turret_cw/light_m2"}
	}

	{on fire "bomber"
		(define "drop_mine_AT"
			{spawn "ptm-1" "kmgu_n%1_%0" x
				{impulse up -2 1 forward 20 rnd_dir 10 com}
					{delay 1 {impulse forward 15 com}}
					{delay 0.5 {impulse forward 15 com}}
			}
		)
		(define "drop_mine_AP"
			{spawn "pfm-1" "kmgu_n%1_%0" x
				{impulse up -2 1 forward 20 rnd_dir 10 com}
				   {delay 1 {impulse forward 15 com}}
				   {delay 0.5 {impulse forward 15 com}}
			}
		)

		(define "fire_barrel"
				{play_sound "kmgu_open"}
				{ani_play "kmgu%0"}
				{delay 0.2 ("drop_mine_AT" args %0 0) ("drop_mine_AT" args %0 0) ("drop_mine_AT" args %0 0) {play_sound "kmgu_shoot"}}
				{delay 0.4 ("drop_mine_AT" args %0 1) ("drop_mine_AT" args %0 1) ("drop_mine_AT" args %0 1) {play_sound "kmgu_shoot"}}
				{delay 0.6 ("drop_mine_AT" args %0 2) ("drop_mine_AT" args %0 2) ("drop_mine_AT" args %0 2) {play_sound "kmgu_shoot"}}

				{delay 0.3 ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) {play_sound "kmgu_shoot"}
				}
				{delay 0.5 ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) {play_sound "kmgu_shoot"}
				}
				{delay 0.7 ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3) ("drop_mine_AP" args %0 3)
					("drop_mine_AP" args %0 3) {play_sound "kmgu_shoot"}
				}
		)

	      {if not tagged "su-25_drop_all_mines"
		{if    name "00" ("fire_barrel" args 00)
		else name "01" ("fire_barrel" args 01)
		else name "02" ("fire_barrel" args 02)
		else name "03" ("fire_barrel" args 03)
		else name "04" ("fire_barrel" args 04)
		else name "05" ("fire_barrel" args 05)
		else name "06" ("fire_barrel" args 06)
		else name "07" ("fire_barrel" args 07)
		}
	       else
		("fire_barrel" args 00)
		("fire_barrel" args 01)
		{delay 0.5 ("fire_barrel" args 02)}
		{delay 0.5 ("fire_barrel" args 03)}
		{delay 1 ("fire_barrel" args 04)}
		{delay 1 ("fire_barrel" args 05)}
		{delay 1.5 ("fire_barrel" args 06)}
		{delay 1.5 ("fire_barrel" args 07)}
	     }
	}
}

{"su-25sm_strike"
	{on spawn 
		{add_view	 	"BMP2_canon_fire"	"flashbarrel1"		"Foresight1"}
		{add_view	"flash_cannon_big"		"X-25_shooter_00"			"X-25_shooter_00"}
		{add_view	"flash_cannon_big"		"X-25_shooter_01"			"X-25_shooter_01"}
		{add_view	"flash_cannon_big"		"X-25_shooter_02"			"X-25_shooter_02"}
		{add_view	"flash_cannon_big"		"X-25_shooter_03"			"X-25_shooter_03"}
		{add_view	"flash_cannon_big"		"R60_00"			"R60_00"}
		{add_view	"flash_cannon_big"		"R60_01"			"R60_01"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur1" 0}
		{tags add "no_missile_control"}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
	}
	("air_multibarrel_launcher" weapon(ptur1) shooter(X-25_shooter_) missile(x_25ml_su25_ammo) flashbarrel(X-25_shooter_))
	("air_multibarrel_launcher" weapon(ptur2) shooter(R60_) missile(r60_su25) flashbarrel(R60_))
	("air_gliding_bomber" weapon(bomber) bomb(odab_500_impactor) bomber(bomber_) speed(35) spread(5))
}

{"su-25sm_AT"
	{on spawn 
		{add_view	 	"BMP2_canon_fire"	"flashbarrel1"		"Foresight1"}
		{add_view	"flash_cannon_big"		"R60_00"			"R60_00"}
		{add_view	"flash_cannon_big"		"R60_01"			"R60_01"}
		{add_view "flash_zenit"			"sppu00"	"sppu_shooter_00"}
		{add_view "flash_zenit"			"sppu01"	"sppu_shooter_01"}
		{add_view "flash_zenit"			"sppu02"	"sppu_shooter_02"}
		{add_view "flash_zenit"			"sppu03"	"sppu_shooter_03"}
		{bone hide "Gun_sppu_break_00"}
		{bone hide "Gun_sppu_break_01"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "nar1" 0}
		{tags add "no_missile_control"}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "nar1" 0}
		{weapon_work "ptur2" 0}
		{weapon_work "mgun" 0}
	}
	{on fire "nar1"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "C-25_shooter_%0" x}
				{spawn "startsmoke" "C-25_tail_%0" x}
		)
		{if    ("fire_barrel" args 00) else ("fire_barrel" args 01) }
	}
	("air_gliding_bomber" weapon(bomber) bomb(rbk_500_impactor) bomber(bomber1_) speed(35) spread(5))
	("air_multibarrel_launcher" weapon(ptur2) shooter(R60_) missile(r60_su25) flashbarrel(R60_))
	{on fire "mgun" overload
		{if name "00"
			{view start "sppu00"}	{delay 0.42	{view pause "sppu00"}}
		else  name "01"
			{view start "sppu01"}	{delay 0.42	{view pause "sppu01"}}
		else  name "02"
			{view start "sppu02"}	{delay 0.42	{view pause "sppu02"}}
		else  name "03"
			{view start "sppu03"}	{delay 0.42	{view pause "sppu03"}}
		}
	}
	{on "tear_wingl1"
		{bone cut "Gun_sppu_00"}
		{bone show "Gun_sppu_break_00"}
	}
	{on "tear_wingr1"
		{bone cut "Gun_sppu_01"}
		{bone show "Gun_sppu_break_01"}
	}
}

{"mig-21bis"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view	"flash_cannon_big"		"R60_00"			"R-60_shooter_00"}
		{add_view	"flash_cannon_big"		"R60_01"			"R-60_shooter_01"}
		{add_view	"flash_cannon_big"		"R60_02"			"R-60_shooter_02"}
		{add_view	"flash_cannon_big"		"R60_03"			"R-60_shooter_03"}
		{add_view	"flash_cannon_big"		"R-3c_00"			"R-3c_shooter_00"}
		{add_view	"flash_cannon_big"		"R-3c_01"			"R-3c_shooter_01"}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur3" 0}
		{weapon_work "ptur2" 0}
	}
	("air_multibarrel_launcher" weapon(ptur2) shooter(R-60_shooter_) missile(r60_su25) flashbarrel(R60_shooter_))
	("air_multibarrel_launcher" weapon(ptur3) shooter(r-3c_shooter_) missile(r-3c) flashbarrel(R-3c_shooter_))
	("air_nar_launcher" weapon(nar1) flashbarrel(Shooter_0))
}
{"mig29_talisman"
	{on spawn 
		{volumes "talisman" enable overlap}
		{ani_play "talisman_shrink" -1}
	}
	{on "update_weaponry"
		{if work "ecm_pod" {volumes "talisman" enable overlap}
		else {volumes "talisman" disable overlap}
		}
	}
	{on overlap begin
		{if effector "radioproximity"
		  (mod "mp"
		  {if rand 0.25
			{with_effector {call "detonate"} {with_effector}}
			{volumes "talisman" disable overlap}
			{delay 3 {volumes "talisman" enable overlap}}
		  }
		  )
		  (mod not "mp"
		  {if rand 0.5
			{with_effector {call "detonate"} {with_effector}}
			{volumes "talisman" disable overlap}
			{delay 3 {volumes "talisman" enable overlap}}
		  }
		  )
		}
	}
	{on "fall" {bone cut "talisman_holder"}}
	{on "mp_destroy" {bone cut "talisman_holder"}}
}
{"mig29"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view	 	"flash_gun_big"	"flashbarrel1"		"fxshot"}
		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_00"			"Shooter_r73rvvsd_00"}
		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_01"			"Shooter_r73rvvsd_01"}
		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_02"			"Shooter_r73rvvsd_02"}
		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_03"			"Shooter_r73rvvsd_03"}
		{add_view	"flash_cannon_big"		"Shooter_r27_00"			"Shooter_r27_00"}
		{add_view	"flash_cannon_big"		"Shooter_r27_01"			"Shooter_r27_01"}
		{add_view 	"rok_tail" 		"tailL00" 		"tailL00"}
		{add_view 	"rok_tail" 		"tailL01" 		"tailL01"}
		{add_view 	"rok_tail" 		"tailL02" 		"tailL02"}
		{add_view 	"rok_tail" 		"tailL03" 		"tailL03"}
		{add_view 	"rok_tail" 		"tailL04" 		"tailL04"}
		{add_view 	"rok_tail" 		"tailL05" 		"tailL05"}
		{add_view 	"rok_tail" 		"tailR00" 		"tailR00"}
		{add_view 	"rok_tail" 		"tailR01" 		"tailR01"}
		{add_view 	"rok_tail" 		"tailR02" 		"tailR02"}
		{add_view 	"rok_tail" 		"tailR03" 		"tailR03"}
		{add_view 	"rok_tail" 		"tailR04" 		"tailR04"}
		{add_view 	"rok_tail" 		"tailR05" 		"tailR05"}
		("link_damage_sound_rus")
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
	}
;	{on "u_w_laser_td_damaged"
;	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
		{weapon_work "ptur" 0}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(Shooter_r73rvvsd_) missile(r-73) flashbarrel(Shooter_r73rvvsd_))
	("air_multibarrel_launcher" weapon(ptur2) shooter(Shooter_rvvsd_) missile(rvv-sd) flashbarrel(Shooter_rvvsd_))
	("air_multibarrel_launcher" weapon(ptur1) shooter(Shooter_r27_) missile(r_27er) flashbarrel(Shooter_r27_))
	("air_nar_launcher" weapon(nar3) flashbarrel(B8shooter_))
	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }
	{on fire "nar1"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{view start "tailL%0"}
				{delay 0.42
					{view pause "tailL%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			}
	}
	{on fire "nar2"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{view start "tailR%0"}
				{delay 0.42
					{view pause "tailR%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			}
	}
}
{"mig29k"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view	 	"flash_gun_big"	"flashbarrel1"		"fxshot"}
		{add_view	"flash_cannon_big"		"Shooter_rvvsd_00"			"Shooter_rvvsd_00"}
		{add_view	"flash_cannon_big"		"Shooter_rvvsd_01"			"Shooter_rvvsd_01"}
		{add_view	"flash_cannon_big"		"Shooter_rvvsd_02"			"Shooter_rvvsd_02"}
		{add_view	"flash_cannon_big"		"Shooter_rvvsd_03"			"Shooter_rvvsd_03"}
		{add_view	"flash_cannon_big"		"Shooter_rvvsd_04"			"Shooter_rvvsd_04"}
		{add_view	"flash_cannon_big"		"Shooter_rvvsd_05"			"Shooter_rvvsd_05"}
		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_00"			"Shooter_r73rvvsd_00"}
		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_01"			"Shooter_r73rvvsd_01"}
		{add_view	"flash_cannon_big"		"Shooter_r31_00"			"Shooter_r31_00"}
		{add_view	"flash_cannon_big"		"Shooter_r31_01"			"Shooter_r31_01"}
		{add_view	"flash_cannon_big"		"Shooter_r31_02"			"Shooter_r31_02"}
		{add_view	"flash_cannon_big"		"Shooter_r31_03"			"Shooter_r31_03"}
		("link_damage_sound_rus")
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur2" 0}
	}
;	{on "u_w_laser_td_damaged"
;	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur4" 0}
		{weapon_work "ptur2" 0}
		{weapon_work "ptur" 0}
		{weapon_work "bomber" 0}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(Shooter_r73rvvsd_) missile(r-73) flashbarrel(Shooter_r73rvvsd_))
	("air_multibarrel_launcher" weapon(ptur2) shooter(Shooter_rvvsd_) missile(rvv-sd) flashbarrel(Shooter_rvvsd_))
	("air_multibarrel_launcher" weapon(ptur4) shooter(Shooter_r31_) missile(x31ad) flashbarrel(Shooter_r31_))
	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }
	("single_alt_control")

}
{"MQ9"
	{on spawn 
		{add_view	"flash_cannon_big"		"flashbarrel00"			"hellfire_shooter_00"}
		{add_view	"flash_cannon_big"		"flashbarrel01"			"hellfire_shooter_01"}
		{add_view	"flash_cannon_big"		"flashbarrel02"			"hellfire_shooter_02"}
		{add_view	"flash_cannon_big"		"flashbarrel03"			"hellfire_shooter_03"}

	}
	{on "link_flare_fx" overload}
	{on "eject_all" overload}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/Helicopter/en_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/Helicopter/en_stop"			}
	}
	{on "landing" 
		{ani_stop "ols_work"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur" 0}
		{tags add "no_missile_control"}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "bomber" 0}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur" 0}
		{call "fall"}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
		{ani_play "ols_work" 0.3 loop}
	}
	{on engine off overload
		{call "engine_stop"}
		{play_sound "engine_stop"}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
;	("air_multibarrel_launcher" weapon(ptur) shooter(hellfire_shooter_) missile(hellfire) flashbarrel(flashbarrel))

	{on fire "ptur"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "hellfire_shooter_%0" x}
;				{spawn "proj_probe" "foresight3" x  {tags add "hellfire_shooter_%0"}}
				{set "ptur"}{call "proj_probe"}
				{view start "flashbarrel%0"}
				{delay 0.4
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		}
	}
	{on ground_hit
		{if velocity 1
			{tear "piece_medium_steel" bone "body"
				{impulse up 2 1 dir 2 1}
			}
			{delay 40 {delete}}
		}
	}
	{on "antifire_work" overload
		{call "antifire_not_work"}
		{delay 10
			{if volume "engine" {components "engine" break}}
		}
	}
}
{"MQ9_nato"
	{on spawn 
		{add_view	"flash_cannon_big"		"flashbarrel00"			"brimstone_shooter_00"}
		{add_view	"flash_cannon_big"		"flashbarrel01"			"brimstone_shooter_01"}
		{add_view	"flash_cannon_big"		"flashbarrel02"			"brimstone_shooter_02"}
		{add_view	"flash_cannon_big"		"flashbarrel03"			"brimstone_shooter_03"}

	}
	{on "link_flare_fx" overload}
	{on "eject_all" overload}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/Helicopter/en_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/Helicopter/en_stop"			}
	}
	{on "landing" 
		{ani_stop "ols_work"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur" 0}
		{tags add "no_missile_control"}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "bomber" 0}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur" 0}
		{call "fall"}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
		{ani_play "ols_work" 0.3 loop}
	}
	{on engine off overload
		{call "engine_stop"}
		{play_sound "engine_stop"}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on fire "ptur"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "brimstone_shooter_%0" x}
;				{spawn "proj_probe" "foresight3" x  {tags add "brimstone_shooter_%0"}}
				{set "ptur"}{call "proj_probe"}
				{view start "flashbarrel%0"}
				{delay 0.4
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		}
	}
	{on ground_hit
		{if velocity 1
			{tear "piece_medium_steel" bone "body"
				{impulse up 2 1 dir 2 1}
			}
			{delay 40 {delete}}
		}
	}
	{on "antifire_work" overload
		{call "antifire_not_work"}
		{delay 10
			{if volume "engine" {components "engine" break}}
		}
	}
}
{"wingloong_ii"
	{on spawn 
		{add_view	"flash_cannon_big"		"flashbarrel00"			"hellfire_shooter_00"}
		{add_view	"flash_cannon_big"		"flashbarrel01"			"hellfire_shooter_01"}
		{add_view	"flash_cannon_big"		"flashbarrel02"			"hellfire_shooter_02"}
		{add_view	"flash_cannon_big"		"flashbarrel03"			"hellfire_shooter_03"}
		{add_view	"flash_cannon_big"		"flashbarrel04"			"hellfire_shooter_04"}
		{add_view	"flash_cannon_big"		"flashbarrel05"			"hellfire_shooter_05"}
		{add_view	"flash_cannon_big"		"flashbarrel06"			"hellfire_shooter_06"}
		{add_view	"flash_cannon_big"		"flashbarrel07"			"hellfire_shooter_07"}
	}
	{on "link_flare_fx" overload}
	{on "eject_all" overload}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/helicopter/en_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/helicopter/en_stop"			}
	}
	{on "landing" 
		{ani_stop "ols_work"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur" 0}
		{tags add "no_missile_control"}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur" 0}
		{call "fall"}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
		{ani_play "ols_work" 0.3 loop}
	}
	{on engine off overload
		{call "engine_stop"}
		{play_sound "engine_stop"}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(hellfire_shooter_) missile(ag300m) flashbarrel(flashbarrel))
	("air_multibomb_launcher" weapon(bomber) shooter(bomber_) missile(cs-bbm2_guided))
	{on ground_hit
		{if velocity 1
			{tear "piece_medium_steel" bone "body"
				{impulse up 2 1 dir 2 1}
			}
			{delay 40 {delete}}
		}
	}
	{on "antifire_work" overload
		{call "antifire_not_work"}
		{delay 10
			{if volume "engine" {components "engine" break}}
		}
	}
}
{"f-22"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_00"			"AIM120C_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_01"			"AIM120C_shooter_01"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_02"			"AIM120C_shooter_02"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_03"			"AIM120C_shooter_03"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_04"			"AIM120C_shooter_04"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_05"			"AIM120C_shooter_05"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_00"			"AIM9M_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_01"			"AIM9M_shooter_01"}
			("link_damage_sound_usa")
	}
	{on "tear_part" 
		{if component "wingl2" {components "ecm" destroy}
		else component "wingr2" {components "ecm" destroy}}
	}
	{on "u_w_hydrosystem_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur" 0}
		{weapon_work "bomber" 0}
		{weapon_work "gun" 0}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur" 0}
	}
	{on "u_w_electronics_damaged"
		{call "fall"}
	}
	{on fire "gun"
		{if not flag "radar_up"	;никакого отношения к радару не имеет, флаг открытия заслонки пушки
			{set "radar_up" 1}
			{ani_play "gun_open"}
		}
		{delay 0.42 "shell_off"
			{set "radar_up" 0}
			{ani_play "gun_open" -1}
		}
	}

	(define "manage_bay"
		{ani_play "bay%0_open"}
		{delay 0.6 {ani_play "bay%0_open" -1}}
	)
	{on fire "ptur"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{delay 0.2 {spawn "aim-120c7_drop_carrier" "AIM120C_shooter_%0" x }}
				{view start "AIM120C_shooter_%0"}
				{delay 0.4
					{view pause "AIM120C_shooter_%0"}
				}
		)
		{if    ("fire_barrel" args 00) ("manage_bay" args 2) 
		else ("fire_barrel" args 01) ("manage_bay" args 3)
		else ("fire_barrel" args 02) ("manage_bay" args 2)
		else ("fire_barrel" args 03) ("manage_bay" args 3)
		else ("fire_barrel" args 04) ("manage_bay" args 2)
		else ("fire_barrel" args 05) ("manage_bay" args 3)}
	}
	{on fire "ptur1"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{delay 0.2 {spawn "aim-9l_carrier" "AIM9M_shooter_%0" x}}
				{view start "AIM9M_shooter_%0"}
				{delay 0.4
					{view pause "AIM9M_shooter_%0"}
				}
		)
		{if    ("fire_barrel" args 00) ("manage_bay" args 1)
		else ("fire_barrel" args 01) ("manage_bay" args 4)}
	}
	{on fire "bomber"
		{if   name "00" ("manage_bay" args 2)
		else  name "01"  ("manage_bay" args 3)}
	}
}
{"f-35"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_00"			"AIM120C_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_01"			"AIM120C_shooter_01"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_02"			"AIM120C_shooter_02"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_03"			"AIM120C_shooter_03"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_04"			"AIM120C_shooter_04"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_05"			"AIM120C_shooter_05"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_06"			"AIM120C_shooter_06"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_07"			"AIM120C_shooter_07"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_00"			"AIM9M_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_01"			"AIM9M_shooter_01"}
		{add_view	"flash_cannon_big"		"jsm_shooter_00"				"jsm_shooter_00"}
		{add_view	"flash_cannon_big"		"jsm_shooter_01"				"jsm_shooter_01"}
		{add_view	"flash_cannon_big"		"jsm_shooter_02"				"jsm_shooter_02"}
		{add_view	"flash_cannon_big"		"jsm_shooter_03"				"jsm_shooter_03"}
			("link_damage_sound_usa")
	}
	{on "tear_part" 
		{if component "wingfront1" {components "ecm" destroy}
		else component "wingfront2" {components "ecm" destroy}
		else component "wingl1" {components "Hydrosystem_tank" destroy}
		else component "wingr1" {components "Hydrosystem_tank" destroy}
		else component "tail1" {components "fuel_tank_internal_c" destroy}
		else component "tail2" {components "fuel_tank_internal_d" destroy}
		else volume "part17" {components "ptur" destroy}
		else volume "part18" {components "ptur" destroy}
		else volume "part20" {components "gun" destroy}{components "ammo_storage_autocannon" destroy}
		}
	}
	{on "u_w_hydrosystem_damaged"
		{weapon_work "ptur" 0}
		{weapon_work "bomber" 0}
		{weapon_work "gun" 0}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur" 0}
	}
	{on "u_w_electronics_damaged"
		{call "fall"}
	}
	{on "_burn" overload
		{damage_report "engine" "burn_fire"}
		{log "burn_volume"}
		{if not burned
			{log "burn_engine"}				
			("burn_engine" engine(1) engine1(0) engine2(0) enginea(0) engineb(0) enginec(0) engined(0))
		}
	}
	(define "manage_bay"
		{ani_play "bay%0_open"}
	)
	{on fire "ptur"
		("low_speed_bullet")
		(define "fire_barrel_drop"
			name "%0"
				{delay 0.2 {spawn "aim-120c7_drop_carrier" "AIM120C_shooter_%0" x}}
				{view start "AIM120C_shooter_%0"}
				{delay 0.4
					{view pause "AIM120C_shooter_%0"}
				}
		)
		(define "fire_barrel"
			name "%0"
				{delay 0.2 {spawn "aim-120c7_carrier" "AIM120C_shooter_%0" x}}
				{view start "AIM120C_shooter_%0"}
				{delay 0.4
					{view pause "AIM120C_shooter_%0"}
				}
		)
		{if    ("fire_barrel_drop" args 00) ("manage_bay" args 2) 
		else ("fire_barrel_drop" args 01) ("manage_bay" args 1)
		else ("fire_barrel_drop" args 02) ("manage_bay" args 2) 
		else ("fire_barrel_drop" args 03) ("manage_bay" args 1) 
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)
		else ("fire_barrel" args 06)
		else ("fire_barrel" args 07)}
	}
	{on fire "ptur1"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{delay 0.2 {spawn "aim-9l_carrier" "AIM9M_shooter_%0" x}}
				{view start "AIM9M_shooter_%0"}
				{delay 0.4
					{view pause "AIM9M_shooter_%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)}
	}
	{on fire "ptur2"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{delay 0.2 {spawn "jsm_carrier" "jsm_shooter_%0" x}}
				{view start "jsm_shooter_%0"}
				{delay 0.4
					{view pause "jsm_shooter_%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)}
	}
	{on fire "bomber"
		{if   name "00" ("manage_bay" args 2)
		else  name "01"  ("manage_bay" args 1)}
	}
	{on fire "bomber1"
	}
	{on fire "bomber2"
		{if name "00"
			{delay 0.2 {spawn "agm-154_carrier" "bomberb_00" x}}
		else  name "01"
			{delay 0.2 {spawn "agm-154_carrier" "bomberb_01" x}}
		}
	}
	("single_alt_control")
}
{"f-35b"
	{on "link_engine_effects"
		{add_view	"turbovent_exhaust"	"add_airstream"		"fx_exhaust1"}
		{add_view	"turbovent_exhaust"	"add_airstream"		"fx_exhaust2"}
		{add_view	"turbovent_exhaust"	"add_airstream"		"fx_exhaust3"}
	}
	{on "takeoff" {delay 3 {view pause "add_airstream"}}}
	{on "takeoff_load" {delay 3 {view pause "add_airstream"}}}
	{on "landing" {delay 2 {view start "add_airstream"}}}
	{on "engine_on"  {if not chassis "airborne" {view start "add_airstream"}}}
	{on engine off {view pause "add_airstream"}}
	{on "check_takeoff_speed" overload
	      {if not chassis "airborne"
			{if velocity 30
				{if terrain_pp "road"
				else terrain_pp "country_road"
				else 
					{components "wheel_back" break}
					{components "retract_wheelR" break}
					{components "retract_wheelL" break}
				}
			}
			{if work "aileron1"
				{if work "aileron2"
					{if velocity 20	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
				else
					{if velocity 22	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
				}
			else
				{if work "aileron2"
					{if velocity 22	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
				else
					{if velocity 25	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
				}
			}
	       }
		{delay 0.2
		   {if flag "engine_started"
		        {if not chassis "airborne"
			{call "check_takeoff_speed"}
		         else  not tagged "takeoff_speed"
			{impulse forward 5 3 no_position}
			{chassis_work 0}
			{call "tear_wheelright"}
			{call "tear_wheelleft"}
			{call "tear_wheelfront"}
			{call "mp_destroy"}
		        }
		    }
		}
	}
}
{"f-15"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_00"			"AIM120C_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_01"			"AIM120C_shooter_01"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_02"			"AIM120C_shooter_02"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_03"			"AIM120C_shooter_03"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_04"			"AIM120C_shooter_04"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_05"			"AIM120C_shooter_05"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_00"			"AIM9M_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_01"			"AIM9M_shooter_01"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_02"			"AIM9M_shooter_02"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_03"			"AIM9M_shooter_03"}
			("link_damage_sound_usa")
	}
	{on "u_w_hydrosystem_damaged"
		{weapon_work "gun" 0}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur" 0}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur" 0}
		{weapon_work "ptur1" 0}
	}
	("air_multibarrel_launcher" weapon(ptur1) shooter(AIM9M_shooter_) missile(aim-9l) flashbarrel(AIM9M_shooter_))
}
{"f-15c_aa"
	("air_multibarrel_launcher" weapon(ptur) shooter(AIM120C_shooter_) missile(aim-120c7) flashbarrel(AIM120C_shooter_))
}
{"f-15j_aa"
	{on spawn 
		{add_view	"flash_cannon_big"		"AIM7_shooter_00"			"AIM7_shooter_00"}
		{add_view	"flash_cannon_big"		"AIM7_shooter_01"			"AIM7_shooter_01"}
		{add_view	"flash_cannon_big"		"AIM7_shooter_02"			"AIM7_shooter_02"}
		{add_view	"flash_cannon_big"		"AIM7_shooter_03"			"AIM7_shooter_03"}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(AIM7_shooter_) missile(aim7m_air) flashbarrel(AIM7_shooter_))
}

{"f-15e_strike"
	("air_multibarrel_launcher" weapon(ptur2) shooter(slam_shooter_) missile(slam_er) flashbarrel(slam_shooter_))
	("air_multibomb_launcher" weapon(bomber1) shooter(bombera_) missile(gbu39_guided))
}
{"f-15e_strike2"
	("air_multibarrel_launcher" weapon(ptur2) shooter(slam_shooter_) missile(slam_er) flashbarrel(slam_shooter_))
	("air_multibomb_launcher" weapon(bomber1) shooter(sdb2_launch_) missile(gbu53b_guided))
}
{"f-15e_support"
	("air_multibarrel_launcher" weapon(ptur2) shooter(slam_shooter_) missile(agm-130) flashbarrel(slam_shooter_))
}
{"f-15e_kab"
	("air_multibomb_launcher" weapon(bomber1) shooter(bomberc_) missile(jdam_er_guided))
}
{"f-15e_sdb"
	("air_multibomb_launcher" weapon(bomber1) shooter(bombera_) missile(gbu39_guided))
	("air_multibomb_launcher" weapon(bomber2) shooter(sdb2_launch_) missile(gbu53b_guided))
}
{"f-16c"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view	"flash_cannon_big"		"AIM120C_shooter_00"			"AIM120C_shooter_00"}
		{add_view	"flash_cannon_big"		"AIM120C_shooter_01"			"AIM120C_shooter_01"}
		{add_view	"flash_cannon_big"		"AIM120C_shooter_02"			"AIM120C_shooter_02"}
		{add_view	"flash_cannon_big"		"AIM120C_shooter_03"			"AIM120C_shooter_03"}
		{add_view	"flash_cannon_big"		"AIM9M_shooter_00"			"AIM9M_shooter_00"}
		{add_view	"flash_cannon_big"		"AIM9M_shooter_01"			"AIM9M_shooter_01"}
		{add_view	"flash_cannon_big"		"AIM9M_shooter_02"			"AIM9M_shooter_02"}
		{add_view	"flash_cannon_big"		"AIM9M_shooter_03"			"AIM9M_shooter_03"}
		{add_view	"flash_cannon_big"		"AGM-86-88_shooter_00"			"AGM-86-88_shooter_00"}
		{add_view	"flash_cannon_big"		"AGM-86-88_shooter_01"			"AGM-86-88_shooter_01"}
		{add_view	"flash_cannon_big"		"AGM-65G_shooter_00"			"AGM-65G_shooter_00"}
		{add_view	"flash_cannon_big"		"AGM-65G_shooter_01"			"AGM-65G_shooter_01"}
		{add_view	"flash_cannon_big"		"flashbarrel4"			"missile_r_rot1"}
		{add_view	"flash_cannon_big"		"flashbarrel5"			"missile_l_rot1"}
			("link_damage_sound_usa")
	}
	{on "u_w_hydrosystem_damaged"
		{weapon_work "ptur" 0}
		{weapon_work "bomber" 0}
		{weapon_work "gun" 0}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur" 0}
		{weapon_work "ptur1" 0}
		{weapon_work "ptur3" 0}
		{weapon_work "ptur5" 0}
	}
	{on "u_w_electronics_damaged"
		{call "fall"}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(AIM120C_shooter_) missile(aim-120c7) flashbarrel(AIM120C_shooter_))
	("air_multibarrel_launcher" weapon(ptur1) shooter(AIM9M_shooter_) missile(aim-9l) flashbarrel(AIM9M_shooter_))
	("air_compact_launcher" weapon(ptur2) missile(agm-65d) foresight(Foresight5) flashbarrel(flashbarrel5))
	("air_compact_launcher" weapon(ptur3) missile(agm-65d) foresight(Foresight4) flashbarrel(flashbarrel4))
	("air_multibarrel_launcher" weapon(ptur4) shooter(AGM-65G_shooter_) missile(agm-65g) flashbarrel(AGM-65G_shooter_))

	{on fire "bomber2"
		{if name "00"
			{delay 0.2 {spawn "agm-154_carrier" "bomberb_00" x}}
		else  name "01"
			{delay 0.2 {spawn "agm-154_carrier" "bomberb_01" x}}
		}
	}
	{on "_burn" overload
		{damage_report "engine" "burn_fire"}
		{log "burn_volume"}
		{if not burned
			{log "burn_engine"}				
			("burn_engine" engine(1) engine1(0) engine2(0) enginea(0) engineb(0) enginec(0) engined(0))
		}
	}
	{on "antifire_work" overload
		{call "antifire_not_work"}
		{delay 10
			{if volume "engine" {components "engine" break}}
		}
	}
}

{"f-16c_antirad"
	("air_multibarrel_launcher" weapon(ptur5) shooter(AGM-86-88_shooter_) missile(agm88) flashbarrel(AGM-86-88_shooter_))
}
{"f-16c_antiship"
	("air_multibarrel_launcher" weapon(ptur5) shooter(AGM-86-88_shooter_) missile(agm-84d) flashbarrel(AGM-86-88_shooter_))
}
{"f-16c_sdb"
	("air_multibomb_launcher" weapon(bomber1) shooter(bombera_) missile(gbu39_guided))
}

{"tornado"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view "flash_gun_big" "flashbarrel1" "gun_shooter01"}
		
		{add_view	"flash_cannon_big"		"AIM9M_shooter_00"			"AIM9M_shooter_00"}
		{add_view	"flash_cannon_big"		"AIM9M_shooter_01"			"AIM9M_shooter_01"}
		{add_view	"flash_cannon_big"		"AIM9M_shooter_02"			"AIM9M_shooter_02"}
		{add_view	"flash_cannon_big"		"AIM9M_shooter_03"			"AIM9M_shooter_03"}

		{add_view	"flash_cannon_big"		"alarm_shooter_00"			"alarm_shooter_00"}
		{add_view	"flash_cannon_big"		"alarm_shooter_01"			"alarm_shooter_01"}
		{add_view	"flash_cannon_big"		"alarm_shooter_02"			"alarm_shooter_02"}
		{add_view	"flash_cannon_big"		"alarm_shooter_03"			"alarm_shooter_03"}

		{add_view	"flash_cannon_big"		"alarma_shooter_00"			"alarma_shooter_00"}
		{add_view	"flash_cannon_big"		"alarma_shooter_01"			"alarma_shooter_01"}

		{add_view	"flash_cannon_big"		"brimstone_shooter_00"			"brimstone_shooter_00"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_01"			"brimstone_shooter_01"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_02"			"brimstone_shooter_02"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_03"			"brimstone_shooter_03"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_04"			"brimstone_shooter_04"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_05"			"brimstone_shooter_05"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_06"			"brimstone_shooter_06"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_07"			"brimstone_shooter_07"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_08"			"brimstone_shooter_08"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_09"			"brimstone_shooter_09"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_10"			"brimstone_shooter_10"}
		{add_view	"flash_cannon_big"		"brimstone_shooter_11"			"brimstone_shooter_11"}

		{add_view	"flash_cannon_big"		"taurus_shooter_00"			"taurus_shooter_00"}
		{add_view	"flash_cannon_big"		"taurus_shooter_01"			"taurus_shooter_01"}

		("link_damage_sound_usa")
	}
	{on engine off
		{if tagged "air_brake_ground" {ani_play "air_brake_ground" -1} {tags remove "air_brake_ground"}}
	}
	{on brake on	{if not tagged "air_brake_ground" {ani_play "air_brake_ground"} {tags add "air_brake_ground"}}}
	{on brake off	{if tagged "air_brake_ground" {ani_play "air_brake_ground" -1} {tags remove "air_brake_ground"}}}
	{on "takeoff" {if tagged "air_brake_ground" {ani_play "air_brake_ground" -1} {tags remove "air_brake_ground"}}}
	{on "u_w_hydrosystem_damaged"
	}
	{on "u_w_radarx_damaged"
	}
	{on "u_w_electronics_damaged"
		{weapon_work "bomber" 0}
		{call "fall"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur4" 0}
		{weapon_work "bomber1" 0}
	}
	("air_multibarrel_launcher" weapon(ptur1) shooter(AIM9M_shooter_) missile(aim-9l) flashbarrel(AIM9M_shooter_))
	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}}
	{with_linked_entity "driver1"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }

}
{"tornado_gr1_carpet"
	{on fire "bomber2"
		{spawn "startsmoke"}
		{spawn "startsmoke" inv_normal}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward 2.5 0.4 rnd_dir 1.5}}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward 5 0.4 rnd_dir 1.5}}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward 7.5 0.4 rnd_dir 1.5}}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward 10 0.4 rnd_dir 1.5}}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward -2.5 0.4 rnd_dir 1.5}}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward -5 0.4 rnd_dir 1.5}}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward -7.5 0.4 rnd_dir 1.5}}
		{spawn "kleinbombe-44_impactor" {impulse up -4 0.3 forward -10 0.4 rnd_dir 1.5}}
	}
	;Сброс контейнеров перед посадкой не реализован, т. к. при неполной зарядке (и неполном сбросе)
	;все равно придется садиться с MW-1
}
{"tornado_gr4_bomber1"
	("air_multibarrel_launcher" weapon(ptur2) shooter(alarm_shooter_) missile(alarm_missile) flashbarrel(alarm_shooter_))
}
{"tornado_gr4_antirad"
	("air_multibarrel_launcher" weapon(ptur2) shooter(alarm_shooter_) missile(alarm_missile) flashbarrel(alarm_shooter_))
}
{"tornado_gr4_at"
	("air_multibarrel_launcher" weapon(ptur4) shooter(brimstone_shooter_) missile(brimstone) flashbarrel(brimstone_shooter_))
}
{"tornado_gr4_strike"
	("air_multibarrel_launcher" weapon(ptur2) shooter(alarma_shooter_) missile(alarm_missile) flashbarrel(alarma_shooter_))
	("air_multibarrel_launcher" weapon(ptur3) shooter(taurus_shooter_) missile(taurus) flashbarrel(taurus_shooter_))
}
{"tornado_gr4_support"
	("air_multibarrel_launcher" weapon(ptur2) shooter(alarm_shooter_) missile(alarm_missile) flashbarrel(alarm_shooter_))
	("air_multibarrel_launcher" weapon(ptur4) shooter(brimstone_shooter_) missile(brimstone) flashbarrel(brimstone_shooter_))
	{on spawn
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter19"}
		{add_view 	"rok_tail" 		"rok_tail20" 		"shooter20"}
		{add_view 	"rok_tail" 		"rok_tail21" 		"shooter21"}
		{add_view 	"rok_tail" 		"rok_tail22" 		"shooter22"}
		{add_view 	"rok_tail" 		"rok_tail23" 		"shooter23"}
		{add_view 	"rok_tail" 		"rok_tail24" 		"shooter24"}
		{add_view 	"rok_tail" 		"rok_tail25" 		"shooter25"}
		{add_view 	"rok_tail" 		"rok_tail26" 		"shooter26"}
		{add_view 	"rok_tail" 		"rok_tail27" 		"shooter27"}
		{add_view 	"rok_tail" 		"rok_tail28" 		"shooter28"}
		{add_view 	"rok_tail" 		"rok_tail29" 		"shooter29"}
		{add_view 	"rok_tail" 		"rok_tail30" 		"shooter30"}
		{add_view 	"rok_tail" 		"rok_tail31" 		"shooter31"}
		{add_view 	"rok_tail" 		"rok_tail32" 		"shooter32"}
		{add_view 	"rok_tail" 		"rok_tail33" 		"shooter33"}
		{add_view 	"rok_tail" 		"rok_tail34" 		"shooter34"}
		{add_view 	"rok_tail" 		"rok_tail35" 		"shooter35"}
		{add_view 	"rok_tail" 		"rok_tail36" 		"shooter36"}
		{add_view 	"rok_tail" 		"rok_tail37" 		"shooter37"}
	}
	("air_nar_launcher" weapon(nar1) flashbarrel(rok_tail))
}

{"eurofighter"
	{on spawn
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view "flash_gun_big" "flashbarrel1" "gun_shooter01"}

;		{add_view	"flash_cannon_big"		"AIM9M_shooter_00"			"AIM9M_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM9M_shooter_01"			"AIM9M_shooter_01"}

;		{add_view	"flash_cannon_big"		"AIM120C_shooter_00"			"AIM120C_shooter_00"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_01"			"AIM120C_shooter_01"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_02"			"AIM120C_shooter_02"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_03"			"AIM120C_shooter_03"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_04"			"AIM120C_shooter_04"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_05"			"AIM120C_shooter_05"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_06"			"AIM120C_shooter_06"}
;		{add_view	"flash_cannon_big"		"AIM120C_shooter_07"			"AIM120C_shooter_07"}

;		{add_view	"flash_cannon_big"		"alarm_shooter_00"			"alarm_shooter_00"}
;		{add_view	"flash_cannon_big"		"alarm_shooter_01"			"alarm_shooter_01"}
;		{add_view	"flash_cannon_big"		"alarm_shooter_02"			"alarm_shooter_02"}
;		{add_view	"flash_cannon_big"		"alarm_shooter_03"			"alarm_shooter_03"}

;		{add_view	"flash_cannon_big"		"brimstone_shooter_00"			"brimstone_shooter_00"}
;		{add_view	"flash_cannon_big"		"brimstone_shooter_01"			"brimstone_shooter_01"}
;		{add_view	"flash_cannon_big"		"brimstone_shooter_02"			"brimstone_shooter_02"}
;		{add_view	"flash_cannon_big"		"brimstone_shooter_03"			"brimstone_shooter_03"}
;		{add_view	"flash_cannon_big"		"brimstone_shooter_04"			"brimstone_shooter_04"}
;		{add_view	"flash_cannon_big"		"brimstone_shooter_05"			"brimstone_shooter_05"}

;		{add_view	"flash_cannon_big"		"taurus_shooter_00"			"taurus_shooter_00"}
;		{add_view	"flash_cannon_big"		"taurus_shooter_01"			"taurus_shooter_01"}
		
		("link_damage_sound_usa")
		{tags remove "towed_decoy1_deployed"}
		{tags remove "towed_decoy2_deployed"}
		{delay 0.5
			{with_linked_entity "cwps_emitter1" {tags add "disabled"}}
			{with_linked_entity "cwps_emitter2" {tags add "disabled"}}
		}
	}
	{on "u_w_hydrosystem_damaged"
		{weapon_work "ptur2" 0}
		{weapon_work "bomber" 0}
		{weapon_work "bomber1" 0}
		{weapon_work "gun" 0}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur2" 0}
	}
	{on "u_w_targeting_pod_damaged"
		{weapon_work "bomber" 0}
		{weapon_work "bomber1" 0}
		{weapon_work "ptur4" 0}
	}
	{on "u_w_electronics_damaged"
		{call "fall"}
	}
	
;--------------towed decoy code
{on blast_hit overload
	{if volume "towed_decoy1" {components "towed_decoy1" break}
	else volume "towed_decoy2" {components "towed_decoy2" break}
	else {inherited}}
}
	(define "deploy_towdecoy"
			{ani_play "towed_decoy%0_deploy"}
			{delay 0.5 {ani_play "towed_decoy%0_randmove"}}
			{tags add "towed_decoy%0_deployed"}
			{with_linked_entity "cwps_emitter%0" {tags remove "disabled"}}
	)
	(define "retract_towdecoy"
		{ani_play "towed_decoy%0_deploy" -1}{tags remove "towed_decoy%0_deployed"}
		{with_linked_entity "cwps_emitter%0" {tags add "disabled"}}
	)
	(define "hide_towdecoy"
		{ani_wind "towed_decoy%0_deploy" begin}{tags remove "towed_decoy%0_deployed"}
		{with_linked_entity "cwps_emitter%0" {tags add "disabled"}}
	)
	{on "radar_warn"
		{if chassis "airborne"
		  {if tagged "towed_decoy1_deployed"	{kill_delay "towdecoy1"} {delay 10 "towdecoy1" ("retract_towdecoy" args 1)}
		  else tagged "towed_decoy2_deployed"	{kill_delay "towdecoy2"} {delay 10 "towdecoy2" ("retract_towdecoy" args 2)}
		  else work "towed_decoy1"
			("deploy_towdecoy" args 1)
			{delay 10 "towdecoy1" ("retract_towdecoy" args 1)}
		  else work "towed_decoy2"
			("deploy_towdecoy" args 2)
			{delay 10 "towdecoy2" ("retract_towdecoy" args 2)}
		  
		 }
		}
	}
	{on "landing"
		{if tagged "towed_decoy1_deployed" ("retract_towdecoy" args 1)
		 else tagged "towed_decoy2_deployed" ("retract_towdecoy" args 2)
		}
	}
	{on "landing_load"
		{if tagged "towed_decoy1_deployed" ("retract_towdecoy" args 1)
		 else tagged "towed_decoy2_deployed" ("retract_towdecoy" args 2)
		}
	}
	{on "mp_destroy" ("hide_towdecoy" args 1) ("hide_towdecoy" args 2)}
;-------------towed decoy code end

	("air_multibarrel_launcher" weapon(ptur1) shooter(AIM9M_shooter_) missile(aim-9l) flashbarrel(AIM9M_shooter_))
	("air_multibarrel_launcher_4drop" weapon(ptur2) shooter(AIM120C_shooter_) missile(aim-120c7) flashbarrel(AIM120C_shooter_))
	("air_multibarrel_launcher" weapon(ptur5) shooter(alarm_shooter_) missile(alarm_missile) flashbarrel(alarm_shooter_))
	("air_multibarrel_launcher" weapon(ptur3) shooter(taurus_shooter_) missile(taurus) flashbarrel(taurus_shooter_))
	("air_multibarrel_launcher" weapon(ptur4) shooter(brimstone_shooter_) missile(brimstone) flashbarrel(brimstone_shooter_))
	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }
	{on fire "bombera" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }



}
{"su-34"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
;		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_00"			"Shooter_r73rvvsd_00"}
;		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_01"			"Shooter_r73rvvsd_01"}
;		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_02"			"Shooter_r73rvvsd_02"}
;		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_03"			"Shooter_r73rvvsd_03"}
;		{add_view	"flash_cannon_big"		"Shooter_r27_00"			"Shooter_r27_00"}
;		{add_view	"flash_cannon_big"		"Shooter_r27_01"			"Shooter_r27_01"}
;		{add_view	"flash_cannon_big"		"Shooter_r27_02"			"Shooter_r27_02"}
;		{add_view	"flash_cannon_big"		"Shooter_r27_03"			"Shooter_r27_03"}
;		{add_view	"flash_cannon_big"		"Shooter_r27_04"			"Shooter_r27_04"}
;		{add_view	"flash_cannon_big"		"Shooter_r27_05"			"Shooter_r27_05"}
;		{add_view	"flash_cannon_big"		"Shooter_r31_00"			"Shooter_r31_00"}
;		{add_view	"flash_cannon_big"		"Shooter_r31_01"			"Shooter_r31_01"}
;		{add_view	"flash_cannon_big"		"Shooter_r31_02"			"Shooter_r31_02"}
;		{add_view	"flash_cannon_big"		"Shooter_r31_03"			"Shooter_r31_03"}
;		{add_view	"flash_cannon_big"		"Shooter_r31_04"			"Shooter_r31_04"}
;		{add_view	"flash_cannon_big"		"Shooter_r31_05"			"Shooter_r31_05"}
;		{add_view	"flash_cannon_big"		"Shooter_r31a_00"			"Shooter_r31a_00"}
;		{add_view	"flash_cannon_big"		"Shooter_r31a_01"			"Shooter_r31a_01"}
;		{add_view	"flash_cannon_big"		"Shooter_r31a_02"			"Shooter_r31a_02"}
;		{add_view	"flash_cannon_big"		"Shooter_x58_00"			"Shooter_x58_00"}
;		{add_view	"flash_cannon_big"		"Shooter_x58_01"			"Shooter_x58_01"}
;		{add_view	"flash_cannon_big"		"Shooter_x58_02"			"Shooter_x58_02"}
;		{add_view	"flash_cannon_big"		"Shooter_x58_03"			"Shooter_x58_03"}
;		{add_view	"flash_cannon_big"		"Shooter_x58_04"			"Shooter_x58_04"}
;		{add_view	"flash_cannon_big"		"Shooter_x58_05"			"Shooter_x58_05"}
;		{add_view	"flash_cannon_big"		"Shooter_x59_00"			"Shooter_x59_00"}
;		{add_view	"flash_cannon_big"		"Shooter_x59_01"			"Shooter_x59_01"}
;		{add_view	"flash_cannon_big"		"Shooter_x59_02"			"Shooter_x59_02"}

		("link_damage_sound_rus")
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur3" 0}
		{weapon_work "ptur5" 0}
	}
	{on "u_w_radar_td_damaged"
		{weapon_work "ptur6" 0}
	}
	{on "u_w_electronics_damaged"	;Reserved flight control sys without physical steering
;		{call "fall"}				;but too low probable that crucial blocks are between engines.
		{weapon_work "ptur1" 0}
		{weapon_work "ptur3" 0}
		{weapon_work "ptur5" 0}
		{weapon_work "ptur6" 0}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(Shooter_r73rvvsd_) missile(r-73) flashbarrel(Shooter_r73rvvsd_))
	("air_multibarrel_launcher_4drop_alt" weapon(ptur1) shooter(Shooter_r27_) missile(r_27er) flashbarrel(Shooter_r27_))
	("air_multibarrel_launcher" weapon(ptur2) shooter(Shooter_r31_) missile(x31p) flashbarrel(Shooter_r31_))
	("air_multibarrel_launcher" weapon(ptur3) shooter(Shooter_r73rvvsd_) missile(rvv-sd) flashbarrel(Shooter_r73rvvsd_))
	("air_multibarrel_launcher" weapon(ptur5) shooter(Shooter_x58_) missile(x-38mte) flashbarrel(Shooter_x58_))
	("air_multibarrel_launcher" weapon(ptur6) shooter(Shooter_x59_) missile(x59m) flashbarrel(Shooter_x59_))
	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}}
					{with_linked_entity "driver1"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}}	}
	{on fire "bomber1" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}}
					{with_linked_entity "driver1"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}}	}
	{on fire "bomber2" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}}
					{with_linked_entity "driver1"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}}	}
}
{"su-34_antitank"
	("air_multibarrel_launcher" weapon(bomber) shooter(bomberd_) missile(pbk-500u) flashbarrel(none))
}
{"su-34_bomber"
	("air_multibarrel_launcher" weapon(bomber) shooter(bomber_) missile(pbk-500u) flashbarrel(none))
}
{"su-34_strike"
	("air_multibarrel_launcher" weapon(ptur4) shooter(Shooter_r31a_) missile(x31p) flashbarrel(Shooter_r31a_))
}
{"su-34_support"
	("air_compact_launcher" weapon(bomber) foresight(bombere_00) missile(pbk-500u) flashbarrel(none))
	("air_compact_launcher" weapon(ptur4) foresight(Shooter_r31a_00) missile(x31p) flashbarrel(Shooter_r31a_00))
	{on fire "nar"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "C-25_shooter_%0" x}
				{spawn "startsmoke" "C-25_tail_%0" x}
		)
		{if ("fire_barrel" args 00) else ("fire_barrel" args 01) 
		else ("fire_barrel" args 02) else ("fire_barrel" args 03)
		}
	}
}
{"su-34_umpk"
	("air_multibomb_launcher" weapon(bomber) shooter(ympk_body_) missile(umpk_500_guided))
}
{"su-34_accurate_2"
	("air_multibomb_launcher" weapon(bomber) shooter(ympk_body_) missile(umpk_500_guided))
}
{"su-35"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
;		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_00"			"Shooter_r73rvvsd_00"}
;		{add_view	"flash_cannon_big"		"Shooter_r73rvvsd_01"			"Shooter_r73rvvsd_01"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_00"			"Shooter_rvvsd_00"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_01"			"Shooter_rvvsd_01"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_02"			"Shooter_rvvsd_02"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_03"			"Shooter_rvvsd_03"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_04"			"Shooter_rvvsd_04"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_05"			"Shooter_rvvsd_05"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_06"			"Shooter_rvvsd_06"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_07"			"Shooter_rvvsd_07"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_08"			"Shooter_rvvsd_08"}
;		{add_view	"flash_cannon_big"		"Shooter_rvvsd_09"			"Shooter_rvvsd_09"}
;		{add_view	"flash_cannon_big"		"Shooter_x38_00"			"Shooter_x53_00"}
;		{add_view	"flash_cannon_big"		"Shooter_x38_01"			"Shooter_x53_01"}
;		{add_view	"flash_cannon_big"		"Shooter_x38_02"			"Shooter_x53_02"}
;		{add_view	"flash_cannon_big"		"Shooter_x38_03"			"Shooter_x53_03"}
;		{add_view	"flash_cannon_big"		"Shooter_x38_04"			"Shooter_x53_04"}
;		{add_view	"flash_cannon_big"		"Shooter_x38_05"			"Shooter_x53_05"}
;		{add_view	"flash_cannon_big"		"Shooter_x59_00"			"Shooter_x59_00"}
;		{add_view	"flash_cannon_big"		"Shooter_x59_01"			"Shooter_x59_01"}

		("link_damage_sound_rus")
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur3" 0}
	}
	{on "u_w_radar_td_damaged"
		{weapon_work "ptur6" 0}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "ptur5" 0}
		{weapon_work "bomber" 0}
	}
	{on "u_w_electronics_damaged"	;Reserved flight control sys without physical steering
;		{call "fall"}				;but too low probable that crucial blocks are between engines.
		{weapon_work "ptur3" 0}
		{weapon_work "ptur6" 0}
		{weapon_work "ptur5" 0}
		{weapon_work "bomber" 0}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(Shooter_r73rvvsd_) missile(r-73) flashbarrel(Shooter_r73rvvsd_))
	("air_multibarrel_launcher_6drop" weapon(ptur3) shooter(Shooter_rvvsd_) missile(rvv-sd) flashbarrel(Shooter_rvvsd_))
	("air_multibarrel_launcher" weapon(ptur5) shooter(Shooter_x38_) missile(x-38mte) flashbarrel(Shooter_x38_))
	("air_multibarrel_launcher" weapon(ptur6) shooter(Shooter_x59_) missile(x59m) flashbarrel(Shooter_x59_))

	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }
	
}
{"su-50"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		{add_view	"flash_cannon_big"		"rvv-ae_shooter_00"			"rvv-ae_shooter_00"}
		{add_view	"flash_cannon_big"		"rvv-ae_shooter_01"			"rvv-ae_shooter_01"}
		{add_view	"flash_cannon_big"		"rvv-ae_shooter_02"			"rvv-ae_shooter_02"}
		{add_view	"flash_cannon_big"		"rvv-ae_shooter_03"			"rvv-ae_shooter_03"}
		{add_view	"flash_cannon_big"		"rvv-md_shooter_00"			"rvv-md_shooter_00"}
		{add_view	"flash_cannon_big"		"rvv-md_shooter_01"			"rvv-md_shooter_01"}
		("link_damage_sound_rus")
	}
	{on "tear_part" 
		{if component "wingl2" {components "ecm" destroy}
		else component "wingr2" {components "ecm" destroy}}
	}
	{on "u_w_hydrosystem_damaged"
		{weapon_work "ptur1" 0}
		{weapon_work "ptur" 0}
		{weapon_work "gun" 0}
		{weapon_work "bomber" 0}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur" 0}
		{bone cut "Visor_radarx_L"}
		{bone cut "Visor_radarx_R"}
	}
	{on "u_w_electronics_damaged"
		{call "fall"}
	}

	{on fire "gun"
		{if not flag "radar_up"	;никакого отношения к радару не имеет, флаг открытия заслонки пушки
			{set "radar_up" 1}
			{ani_play "gun_open"}
		}
		{ani_play "gun"}
		{delay 0.42 "shell_off"
			{set "radar_up" 0}
			{ani_play "gun_open" -1}
		}
	}

	(define "manage_bay"
		{ani_play "bay%0_open"}
		{delay 0.6 {ani_play "bay%0_open" -1}}
	)

	{on fire "ptur1"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{delay 0.2 {spawn "rvv-md_carrier" "rvv-md_shooter_%0" x}}
				{view start "rvv-md_shooter_%0"}
				{delay 0.4
					{view pause "rvv-md_shooter_%0"}
				}
		)
		{if    ("fire_barrel" args 00) ("manage_bay" args 1)
		else ("fire_barrel" args 01) ("manage_bay" args 4)}
	}
	{on fire "bomber"
		{if   name "00" ("manage_bay" args 3)
		else  name "01"  ("manage_bay" args 3)
		else  name "02"  ("manage_bay" args 2)
		else  name "03"  ("manage_bay" args 2)}
	}
}
{"su-50_aa"
	{on fire "ptur"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				
				{delay 0.2 {spawn "rvv-ae_carrier" "rvv-ae_shooter_%0" x}}
				{view start "rvv-ae_shooter_%0"}
				{delay 0.4
					{view pause "rvv-ae_shooter_%0"}
				}
		)
		{if    ("fire_barrel" args 00) ("manage_bay" args 2) 
		else ("fire_barrel" args 01) ("manage_bay" args 2)
		else ("fire_barrel" args 02) ("manage_bay" args 3)
		else ("fire_barrel" args 03) ("manage_bay" args 3)}
	}
}
{"su-50_at"
	{on fire "ptur"
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{delay 0.2 {spawn "x-38mte_carrier" "rvv-ae_shooter_%0" x}}
				{view start "rvv-ae_shooter_%0"}
				{delay 0.4
					{view pause "rvv-ae_shooter_%0"}
				}
		)
		{if    ("fire_barrel" args 00) ("manage_bay" args 2) 
		else ("fire_barrel" args 01) ("manage_bay" args 2)
		else ("fire_barrel" args 02) ("manage_bay" args 3)
		else ("fire_barrel" args 03) ("manage_bay" args 3)}
		("cw_check_shooting" weap_id(ptur))	;for single
	}
}

{"an-12"
	{on "link_engine_effects" overload
		{add_view	"exhaust_dark_big"		"enginea_exhaust"		"enginea_exhaust"	}
		{add_view	"exhaust_dark_big"		"engineb_exhaust" 		"engineb_exhaust"	}
		{add_view	"exhaust_dark_big"		"enginec_exhaust"		"enginec_exhaust"	}
		{add_view	"exhaust_dark_big"		"engined_exhaust" 		"engined_exhaust"	}
	}
	{on "link_flare_fx" overload}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/fw_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "fall" 
		{bone hide "Anten"}
	}
	{on fire "gun"
		{spawn "tank_canon_fire_small" inv_normal}
	}
	{on overlap begin
	      {if tagged "rampa_open"
		{if effector "can_paradrop_an-12"
			("load_vehicle")
		}
	       }
	}
	{on "eject_all" overload}
	{on "emit_desant1"
	       {if tagged "place1_busy"
		{delay 0.1 {with_linked_entity "seat00"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat01"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat02"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat03"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat04"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat05"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat06"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat07"	{get_off}	}}
	        }
	}
	{on "emit_desant2"
	       {if tagged "place2_busy"
		{delay 0.1 {with_linked_entity "seat08"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat09"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat10"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat11"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat12"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat13"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat14"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat15"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat16"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat17"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat18"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat19"	{get_off}	}}
	        }
	}
	{on "drop_desant1"
		{delay 0.1 {with_linked_entity "seat00"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat01"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat02"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat03"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat04"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat05"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat06"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat07"	{get_off}	}}
	}
	{on "drop_desant2"
		{delay 0.1 {with_linked_entity "seat08"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat09"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat10"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat11"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat12"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat13"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat14"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat15"	{get_off}	}}
		{delay 1.7 {with_linked_entity "seat16"	{get_off}	}}
		{delay 1.9 {with_linked_entity "seat17"	{get_off}	}}
		{delay 2.1 {with_linked_entity "seat18"	{get_off}	}}
		{delay 2.3 {with_linked_entity "seat19"	{get_off}	}}
	}
}

{"an-12_mp"
	{on spawn
		{tags add "place1_busy"} {ani_wind "vehicle1_in" end}  {bone show "platform1"}
		{tags add "place2_busy"} {ani_wind "vehicle2_in" end}  {bone show "platform2"}
	}
}
{"an-12bk"
	{on "emit_desant1"
	       {if tagged "place1_busy"
		{delay 0.1 {with_linked_entity "seat00"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat01"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat02"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat03"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat04"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat05"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat06"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat07"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat08"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat09"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat10"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat11"	{get_off}	}}
	        }
	}
	{on "emit_desant2"
	       {if tagged "place2_busy"
		{delay 0.1 {with_linked_entity "seat12"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat13"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat14"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat15"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat16"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat17"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat18"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat19"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat20"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat21"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat22"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat23"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat24"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat25"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat26"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat27"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat28"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat29"	{get_off}	}}
	        }
	}
	{on "drop_desant1"
		{delay 0.1 {with_linked_entity "seat00"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat01"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat02"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat03"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat04"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat05"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat06"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat07"	{get_off}	}}
		{delay 1.7 {with_linked_entity "seat08"	{get_off}	}}
		{delay 1.9 {with_linked_entity "seat09"	{get_off}	}}
		{delay 2.2 {with_linked_entity "seat10"	{get_off}	}}
		{delay 2.4 {with_linked_entity "seat11"	{get_off}	}}
	}
	{on "drop_desant2"
		{delay 0.1 {with_linked_entity "seat12"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat13"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat14"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat15"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat16"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat17"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat18"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat19"	{get_off}	}}
		{delay 1.7 {with_linked_entity "seat20"	{get_off}	}}
		{delay 1.9 {with_linked_entity "seat21"	{get_off}	}}
		{delay 2.1 {with_linked_entity "seat22"	{get_off}	}}
		{delay 2.3 {with_linked_entity "seat23"	{get_off}	}}
		{delay 2.5 {with_linked_entity "seat24"	{get_off}	}}
		{delay 2.7 {with_linked_entity "seat25"	{get_off}	}}
		{delay 2.9 {with_linked_entity "seat26"	{get_off}	}}
		{delay 3.1 {with_linked_entity "seat27"	{get_off}	}}
		{delay 3.3 {with_linked_entity "seat28"	{get_off}	}}
		{delay 3.5 {with_linked_entity "seat29"	{get_off}	}}
	}
	{on "check_vdvstate"
        {if tagged "place1_busy" {ani_wind "vehicle1_in" end} {if not tagged "dont_drop" {bone show "platform1"}}}
        ;{if tagged "place2_busy" {ani_wind "vehicle2_in" end} {if not tagged "dont_drop" {bone show "platform2"}}}
        ;{if tagged "place3_busy" {ani_wind "vehicle3_in" end} {if not tagged "dont_drop" {bone show "platform3"}}}
        ;{if tagged "place4_busy" {ani_wind "vehicle4_in" end} {if not tagged "dont_drop" {bone show "platform4"}}}
        ;{if tagged "place5_busy" {ani_wind "vehicle5_in" end} {if not tagged "dont_drop" {bone show "platform5"}}}
        ;{if tagged "place6_busy" {ani_wind "vehicle6_in" end} {if not tagged "dont_drop" {bone show "platform6"}}}
        ;{if tagged "place7_busy" {ani_wind "vehicle7_in" end} {if not tagged "dont_drop" {bone show "platform7"}}}
        ;{if tagged "place8_busy" {ani_wind "vehicle8_in" end} {if not tagged "dont_drop" {bone show "platform8"}}}
        ;{if tagged "place9_busy" {ani_wind "vehicle9_in" end} {if not tagged "dont_drop" {bone show "platform9"}}}
        ;{if tagged "cargo_open" {ani_wind "cargo_open" end}}
        ;{if tagged "rampa_open" {ani_wind "pandus_open" end}}
    }
}

{"il-76td"
	{on "link_flare_fx" overload}
	{on "link_engine_effects" overload
		{add_view	"turbovent_exhaust"	"enginea_exhaust"		"enginea_exhaust1"	}
		{add_view	"turbovent_exhaust"	"engineb_exhaust"		"engineb_exhaust1"	}
		{add_view	"turbovent_exhaust"	"enginec_exhaust"		"enginec_exhaust1"	}
		{add_view	"turbovent_exhaust"	"engined_exhaust"		"engined_exhaust1"	}
		{add_view	"turbovent_overburn"		"enginea_overburn"		"enginea_exhaust1"	}
		{add_view	"turbovent_overburn"		"engineb_overburn" 		"engineb_exhaust1"	}
		{add_view	"turbovent_overburn"		"enginec_overburn" 		"enginec_exhaust1"	}
		{add_view	"turbovent_overburn"		"engined_overburn" 		"engined_exhaust1"	}
		{add_view	"turbovent_exhaust"	"enginea_exhaust"		"enginea_exhaust2"	}
		{add_view	"turbovent_exhaust"	"engineb_exhaust"		"engineb_exhaust2"	}
		{add_view	"turbovent_exhaust"	"enginec_exhaust"		"enginec_exhaust2"	}
		{add_view	"turbovent_exhaust"	"engined_exhaust"		"engined_exhaust2"	}
		{add_view	"turbovent_overburn"		"enginea_overburn"		"enginea_exhaust2"	}
		{add_view	"turbovent_overburn"		"engineb_overburn" 		"engineb_exhaust2"	}
		{add_view	"turbovent_overburn"		"enginec_overburn" 		"enginec_exhaust2"	}
		{add_view	"turbovent_overburn"		"engined_overburn" 		"engined_exhaust2"	}

	}
	{on "eject_all" overload}
	{on engine off
		{if tagged "air_brake_ground" {ani_play "air_brake_ground" -1} {tags remove "air_brake_ground"}}
	}
	{on brake on	{if not tagged "air_brake_ground" {ani_play "air_brake_ground"} {tags add "air_brake_ground"}}}
	{on brake off	{if tagged "air_brake_ground" {ani_play "air_brake_ground" -1} {tags remove "air_brake_ground"}}}
	{on "takeoff" {if tagged "air_brake_ground" {ani_play "air_brake_ground" -1} {tags remove "air_brake_ground"}}}
	{on "tear_part" 
		{if volume "part7" {components "enginea" destroy} {components "Hydrosystem_tank" destroy}
		else volume "part8" {components "engineb" destroy} {components "antifire" destroy}
		else volume "part9" {components "enginec" destroy} {components "antifire" destroy}
		else volume "part10" {components "engined" destroy} {components "Hydrosystem_tank" destroy}
		}
	}
	{on overlap begin
	      {if tagged "rampa_open"
		{if effector "can_paradrop_il-76td"
			("load_vehicle")
		}
	       }
	}

	{on "emit_desant1"
	       {if tagged "place1_busy"
		{delay 0.1 {with_linked_entity "seat00"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat01"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat02"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat03"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat04"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat05"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat06"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat07"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat08"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat09"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat10"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat11"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat12"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat13"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat14"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat15"	{get_off}	}}
	        }
	}
	{on "emit_desant2"
	       {if tagged "place2_busy"
		{delay 0.1 {with_linked_entity "seat16"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat17"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat18"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat19"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat20"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat21"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat22"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat23"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat24"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat25"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat26"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat27"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat28"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat29"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat30"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat31"	{get_off}	}}
	        }
	}
	{on "emit_desant3"
	       {if tagged "place3_busy"
		{delay 0.1 {with_linked_entity "seat32"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat33"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat34"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat35"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat36"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat37"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat38"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat39"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat40"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat41"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat42"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat43"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat44"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat45"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat46"	{get_off}	}}
		{delay 0.1 {with_linked_entity "seat47"	{get_off}	}}
	        }
	}
	{on "drop_desant1"
		{delay 0.1 {with_linked_entity "seat00"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat01"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat02"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat03"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat04"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat05"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat06"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat07"	{get_off}	}}
		{delay 1.7 {with_linked_entity "seat08"	{get_off}	}}
		{delay 1.9 {with_linked_entity "seat09"	{get_off}	}}
		{delay 2.1 {with_linked_entity "seat10"	{get_off}	}}
		{delay 2.3 {with_linked_entity "seat11"	{get_off}	}}
		{delay 2.5 {with_linked_entity "seat12"	{get_off}	}}
		{delay 2.7 {with_linked_entity "seat13"	{get_off}	}}
		{delay 2.9 {with_linked_entity "seat14"	{get_off}	}}
		{delay 3.1 {with_linked_entity "seat15"	{get_off}	}}
	}
	{on "drop_desant2"
		{delay 0.1 {with_linked_entity "seat16"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat17"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat18"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat19"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat20"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat21"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat22"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat23"	{get_off}	}}
		{delay 1.7 {with_linked_entity "seat24"	{get_off}	}}
		{delay 1.9 {with_linked_entity "seat25"	{get_off}	}}
		{delay 2.1 {with_linked_entity "seat26"	{get_off}	}}
		{delay 2.3 {with_linked_entity "seat27"	{get_off}	}}
		{delay 2.5 {with_linked_entity "seat28"	{get_off}	}}
		{delay 2.7 {with_linked_entity "seat29"	{get_off}	}}
		{delay 2.9 {with_linked_entity "seat30"	{get_off}	}}
		{delay 3.1 {with_linked_entity "seat31"	{get_off}	}}
	}
	{on "drop_desant3"
		{delay 0.1 {with_linked_entity "seat32"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat33"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat34"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat35"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat36"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat37"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat38"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat39"	{get_off}	}}
		{delay 1.7 {with_linked_entity "seat40"	{get_off}	}}
		{delay 1.9 {with_linked_entity "seat41"	{get_off}	}}
		{delay 2.1 {with_linked_entity "seat42"	{get_off}	}}
		{delay 2.3 {with_linked_entity "seat43"	{get_off}	}}
		{delay 2.5 {with_linked_entity "seat44"	{get_off}	}}
		{delay 2.7 {with_linked_entity "seat45"	{get_off}	}}
		{delay 2.9 {with_linked_entity "seat46"	{get_off}	}}
		{delay 3.1 {with_linked_entity "seat47"	{get_off}	}}
	}
}
{"eleron3sv"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "landing"
		{ani_stop "ols_work"}
		{bone show "parashute"}
		{bone hide "cover"}
		{call "engine_stop"}
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{if not work "wheel_front"
		     {call "fall"}
		}
		{delay 15
			{if chassis "airborne"
				 {call "fall"}
			}
		}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
		{ani_play "ols_work" 0.3 loop}
	}
	{on engine off
		{call "engine_stop"}
		{play_sound "engine_stop"}
		{if not chassis "airborne"
			{spawn "eleron_ammo" "basis" x {impulse forward 3}}
			{delete}
		}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
}

{"lancet3m"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
	(define "cut_part"
		{tear "piece_medium_steel" bone %0
			{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			{call "check_delete_part"}
		}
	)
	{on "detonate" overload
		{if rand 0.5 ("cut_part" args "WingL1")}
		{if rand 0.5 ("cut_part" args "WingL2")}
		{if rand 0.5 ("cut_part" args "WingR1")}
		{if rand 0.5 ("cut_part" args "WingR2")}
	    {inherited}
		{stuff_detonate}
	}
	{on "underground_detonate" overload
		{if rand 0.5 ("cut_part" args "WingL1")}
		{if rand 0.5 ("cut_part" args "WingL2")}
		{if rand 0.5 ("cut_part" args "WingR1")}
		{if rand 0.5 ("cut_part" args "WingR2")}
	    {inherited}
		{stuff_detonate}
	}
}
{"lancet3m_fg"	("loitering_munition" missilename(lancet3m_fg))}
{"lancet3m_cm"	("loitering_munition" missilename(lancet3m_cm))}
{"rq11raven"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "landing"
		{call "engine_stop"}
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{delay 15
			{if chassis "airborne"
				 {call "fall"}
			}
		}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on engine off
		{call "engine_stop"}
		{play_sound "engine_stop"}
		{if not chassis "airborne"
			{spawn "rq11raven_b_ammo" "basis" x {impulse forward 3}
				{if rand 0.5 {tear "piece_medium_steel" bone "wingr1" {impulse dir 2 1 forward 2 0.5} {delay 60 {hide 5}}}}
				{if rand 0.5 {tear "piece_medium_steel" bone "elevator" {impulse dir 2 1 forward 2 0.5} {delay 60 {hide 5}}}}
				{if rand 0.5 {tear "piece_medium_steel" bone "part1" {impulse dir 2 1 forward 2 0.5} {delay 60 {hide 5}}}}
			}
			{delete}
		}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
}

{"switchblade300"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
	("loitering_munition" missilename(switchblade300))
}

{"switchblade600"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
	("loitering_munition" missilename(switchblade600))
}

{"shahed136"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/shahed136_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/shahed136_engine"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/shahed136_engine_end"			}
	}
	{on "link_flare_fx" overload}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
		{if not altitude 15
			{link_sound "rocket"		"vehicle/airborne/small_uav/shahed136_rocket"			}
			{play_sound "rocket"}
			{add_view	"proj_jet_atgm"			"proj_jet"			"fx_starter"}
			{view start "proj_jet"}
			{view show "proj_jet"}
			{delay 2 
				{view stop "proj_jet"}
				{view hide "proj_jet"}
				{tear "piece_medium_steel" bone "part4" {impulse forward 5 up -0.1}}
			}
		else
			{bone cut "part4"}
		}
	}
	{on "check_altitude"
		{reset_manual_control}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	;It is not electric, but still very stealthy
	("loitering_munition" missilename(shahed136_base))
	(define "cut_part"
		{tear "piece_medium_steel" bone %0
			{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			{call "check_delete_part"}
		}
	)
	{on "detonate" overload
		{if rand 0.3 ("cut_part" args "part1")}
		{if rand 0.3 ("cut_part" args "tail1")}
		{if rand 0.3 ("cut_part" args "tail2")}
	    {inherited}
		{stuff_detonate}
	}
	{on "underground_detonate" overload
		{if rand 0.3 ("cut_part" args "part1")}
		{if rand 0.3 ("cut_part" args "tail1")}
		{if rand 0.3 ("cut_part" args "tail2")}
	    {inherited}
		{stuff_detonate}
	}
}

{"rq11raven_b_ammo"
	{on "change"
		{spawn "rq11raven_ammo" "root" x}
		{delete}
	}
}
{"rq11raven_ammo"
	{on "onThrow"
		{delay 0.5
			{spawn "rq11raven" "root" dir_velocity no_normal}
			{delete}
		}
	}
}

{"aladin"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "landing"
		{call "engine_stop"}
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{call "loop_detect"}
		{delay 15
			{if chassis "airborne"
				 {call "fall"}
			}
		}
	}
	{on "loop_detect"
		{if not altitude 15 {ani_play "parawing" callback}
		else {delay 0.2 {call "loop_detect"}}}
	}
	{on animation_end "parawing"
			{spawn "aladin_b_ammo" "body" x 
				{impulse up -0.1 forward 0.5} {constrain_velocity 6}
			}
			{delete}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on engine off
		{call "engine_stop"}
		{play_sound "engine_stop"}
	}
	
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
}

{"aladin_b_ammo"
	{on "change"
		{spawn "aladin_ammo" "root" x}
		{delete}
	}
}
{"aladin_ammo"
	{on "onThrow"
		{delay 0.5
			{spawn "aladin" "root" dir_velocity no_normal}
			{delete}
		}
	}
}

{"ch802"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "landing"
		{call "engine_stop"}
		{bone show "parachute"}
		{bone hide "cover"}
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{if not work "wheel_front"
		     {call "fall"}
		}
		{delay 15
			{if chassis "airborne"
				 {call "fall"}
			}
		}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on engine off
		{call "engine_stop"}
		{play_sound "engine_stop"}
		{if not chassis "airborne"
			{spawn "ch802_b_ammo" "basis" x {impulse forward 3}}
			{delete}
		}
	}
	
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
}

{"ch802_b_ammo"
	{on "change"
		{spawn "ch802_ammo" "root" x}
		{delete}
	}
}
{"ch802_ammo"
	{on "onThrow"
		{delay 0.5
			{spawn "ch802" "root" dir_velocity no_normal}
			{delete}
		}
	}
}

{"ch901"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/small_uav/small_uav_start"			}
		{link_sound "engine_work"		"vehicle/airborne/small_uav/small_uav_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/small_uav/small_uav_stop"			}
	}
	{on "link_flare_fx" overload}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	;electric plane cannot be locked by IR active missiles like Igla or Stinger
	;so it has IR active def
	("loitering_munition" missilename(ch901))
}
{"e-2c_hawkeye"
	{on "link_engine_effects" overload
		{add_view	"exhaust_dark_big"		"engine1_exhaust"		"engine1_exhaust"	}
		{add_view	"exhaust_dark_big"		"engine2_exhaust" 		"engine2_exhaust"	}
	}
	{on "link_flare_fx" overload}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/airborne/fw_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "fall" 
		{bone hide "Anten1"}
		{bone hide "Anten2"}
	}
	{on "eject_all" overload}
	{on "takeoff_actions"
		{if work "radarl"
			{ani_play "radar_work" 0.3 loop}
		}
	}
	{on "landing"
		{ani_stop "radar_work"}
	}
	{on "engine_on"
		{if not velocity 5 {ani_play "ladder_in"}}
	}
	{on "engine_stop"
		{if not velocity 5 {if not tagged "destroyed" {ani_play "ladder_in" -1}}}
	}
	{on animation_end "engine1_start" overload
		{ani_play "engine1_work" loop}
	}
	{on animation_end "engine2_start" overload
		{ani_play "engine2_work" loop}
	}

}
{"jh-7a"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		
		{add_view	"flash_cannon_big"		"Shooter_pl5_00"			"Shooter_pl5_00"}
		{add_view	"flash_cannon_big"		"Shooter_pl5_01"			"Shooter_pl5_01"}
		{add_view	"flash_cannon_big"		"Shooter_pl8_00"			"Shooter_pl8_00"}
		{add_view	"flash_cannon_big"		"Shooter_pl8_01"			"Shooter_pl8_01"}

		{add_view	"flash_cannon_big"		"Shooter_main_00"			"Shooter_main_00"}
		{add_view	"flash_cannon_big"		"Shooter_main_01"			"Shooter_main_01"}
		{add_view	"flash_cannon_big"		"Shooter_main_02"			"Shooter_main_02"}
		{add_view	"flash_cannon_big"		"Shooter_main_03"			"Shooter_main_03"}

	}

	{on "u_w_hydrosystem_damaged"
	}
	{on "u_w_radarx_damaged"
	}
	{on "u_w_electronics_damaged"
		{call "fall"}
	}
	{on "u_w_laser_td_damaged"
		{weapon_work "nar" 0}
	}
	{on "u_w_radar_td_damaged"
		{weapon_work "ptur2" 0}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(Shooter_pl5_) missile(pl5e2) flashbarrel(Shooter_pl5_))
	("air_multibarrel_launcher" weapon(ptur1) shooter(Shooter_pl8_) missile(pl8b) flashbarrel(Shooter_pl8_))
	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }
;	{on fire "bomber1" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }
	("air_multibomb_launcher" weapon(bomber1) shooter(bombere_) missile(ls6_guided))
}

{"jh-7a_antirad"
	("air_multibarrel_launcher" weapon(ptur2) shooter(Shooter_main_) missile(ld10) flashbarrel(Shooter_main_))
}
{"jh-7a_strike"
	("air_multibarrel_launcher" weapon(ptur2) shooter(Shooter_main_) missile(c802akg) flashbarrel(Shooter_main_))
}
{"j-10c"
	{on spawn 
		{add_view "flash_gun_big" "flashbarrel1" "foresight1"}
		
		{add_view	"flash_cannon_big"		"Shooter_pl8_00"			"Shooter_pl8_00"}
		{add_view	"flash_cannon_big"		"Shooter_pl8_01"			"Shooter_pl8_01"}

		{add_view	"flash_cannon_big"		"Shooter_pl12_00"			"Shooter_pl12_00"}
		{add_view	"flash_cannon_big"		"Shooter_pl12_01"			"Shooter_pl12_01"}
		{add_view	"flash_cannon_big"		"Shooter_pl12_02"			"Shooter_pl12_02"}
		{add_view	"flash_cannon_big"		"Shooter_pl12_03"			"Shooter_pl12_03"}
		{add_view	"flash_cannon_big"		"Shooter_pl12_04"			"Shooter_pl12_04"}
		{add_view	"flash_cannon_big"		"Shooter_pl12_05"			"Shooter_pl12_05"}
	}
	{on "u_w_electronics_damaged"
		{weapon_work "ptur" 0}
		{weapon_work "ptur1" 0}
		{weapon_work "bomber" 0}
		{call "fall"}
	}
	{on "u_w_radarx_damaged"
		{weapon_work "ptur" 0}
	}
	("air_multibarrel_launcher" weapon(ptur) shooter(Shooter_pl12_) missile(pl12) flashbarrel(Shooter_pl12_))
	("air_multibarrel_launcher" weapon(ptur1) shooter(Shooter_pl8_) missile(pl8b) flashbarrel(Shooter_pl8_))
	;self-shooting fix, does not work with makroses
	{on fire "bomber" {with_linked_entity "driver"	{volumes "body_c" disable bullet} {delay 1 {volumes "body_c" enable bullet}}} }

}
{"maz7410_pricep"
	{on "load_heavy_vehicle"
		{tags add "cargo_inside"}
		{if not tagged "place1_busy"
			{delay 0.1 {ani_play "vehicle1_in" callback}}
			{tags add "vdv_link_place1"} {delay 3 {tags remove "vdv_link_place1"}}
			{tags add "place1_busy"}
			{with_effector {tags add "vdv_link_to_place1"} {delay 3 {tags remove "vdv_link_to_place1"}}}
		}
	}
	{on overlap begin
	      {if not tagged "cargo_inside"
			{if effector "heavy_M"
				{call "load_heavy_vehicle"}
			else  effector "medium_M"
				{call "load_heavy_vehicle"}
			else  effector "armored_car_M"
				{call "load_heavy_vehicle"}
			else  effector "light_M"
				{call "load_heavy_vehicle"}
			else  effector "car"
				{call "load_heavy_vehicle"}
			}
	       }
	}
	{on "script_update_cargo_anim"
		{if tagged "place1_busy" {ani_wind "vehicle1_in" end} else {ani_wind "vehicle1_in" begin}}
	}
	{on "open_cargo" overload
		{unlink_trailer}
		{if not tagged "cargo_open"
			{volumes "vehicle" enable overlap}
		}
		  {if tagged "cargo_inside"
			{tags remove "cargo_inside"}
			{if tagged "place1_busy"
				{volumes disable overlap} {ani_play "vehicle1_unload" callback}
			}
			{tags remove "place1_busy"}
		  else {volumes "vehicle" enable overlap}
		  }
	}
	{on animation_end "vehicle1_unload" overload
		{with_linked_entity "vehicle1"
			{tags add "unlink_me"}
			{able "sinking" 0}
		}
	}
	{on break
		{if component "wheel"
			{bone cut "vehicle"} {bone cut "link1"} {bone cut "vehicle1"} {components "body" break}
		}
	}
}
{"buksir"
	{on "check_water_level"
		{if tagged "cargo_inside"
			{if tagged "cwts_car_linked" {spawn "buksir_informer" "link1" {tags add "cwts_car_linked"}}
			else tagged "cwts_btr_linked" {spawn "buksir_informer" "link1" {tags add "cwts_btr_linked"}}
			else tagged "cwts_bmp_linked" {spawn "buksir_informer" "link1" {tags add "cwts_bmp_linked"}}
			else tagged "cwts_tank_linked" {spawn "buksir_informer" "link1" {tags add "cwts_tank_linked"}}
			}
		}
	}
	{on "load_heavy_vehicle"
		{tags add "cargo_inside"}
		{call "check_sinking"}
		{if not tagged "place1_busy"
			{delay 0.1 {ani_play "vehicle1_in" callback}}
			{tags add "vdv_link_place1"} {delay 3 {tags remove "vdv_link_place1"}}
			{tags add "place1_busy"}
		}
	}
	{on "script_update_cargo_anim"
		{if tagged "place1_busy" {ani_wind "vehicle1_in" end} else {ani_wind "vehicle1_in" begin}}
	}
	{on "open_cargo" overload
		{unlink_trailer}
		{if not tagged "cargo_open"
			{volumes "vehicle" enable overlap}
		}
		  {if tagged "cargo_inside"
			{tags remove "cargo_inside"}
			{if tagged "place1_busy"
				{volumes disable overlap} {ani_play "vehicle1_unload" callback}
			}
			{tags remove "place1_busy"}
		  else {volumes "vehicle" enable overlap}
		  }
	}
	{on animation_end "vehicle1_unload" overload
		{call "open"}
	}
	{on "open"
		{bone cut "vehicle1"}
		{spawn "buksir_tros" "open_point" {impulse up 0.01 com}}
		{delete}
	}
}
{"buksir_informer"
	{on spawn 
		{impulse up 0.1 com} {delay 0.5 {delete}}
	}
	{on contact	
		(define "load_type"
			{call "update_moveability"}
			{kill_delay "cwts"}
			{tags add "cwts_%type"}
			{delay 1 "cwts"
				{tags remove "cwts_%type"} {call "update_moveability"}
			}
		)
	    {if effector "car"
			{if tagged "cwts_car_linked" {with_effector ("load_type" type(heavy)){with_effector}}
			else tagged "cwts_btr_linked" {with_effector {unlink_trailer} {components "engine" break} {with_effector}}
			else tagged "cwts_bmp_linked" {with_effector {unlink_trailer} {components "engine" break} {with_effector}}
			else tagged "cwts_tank_linked" {with_effector {unlink_trailer} {components "engine" break} {with_effector}}
			}
		else effector "tank armored_car_M"
			{if tagged "cwts_car_linked" {with_effector ("load_type" type(normal)) {with_effector}}
			else tagged "cwts_btr_linked" {with_effector ("load_type" type(heavy)) {with_effector}}
			else tagged "cwts_bmp_linked" {with_effector {unlink_trailer} {components "transmission" break} {with_effector}}
			else tagged "cwts_tank_linked" {with_effector {unlink_trailer} {components "transmission" break} {with_effector}}
			}
		else effector "tank light_M"
			{if tagged "cwts_car_linked" {with_effector ("load_type" type(light)){with_effector}}
			else tagged "cwts_btr_linked" {with_effector ("load_type" type(normal)){with_effector}}
			else tagged "cwts_bmp_linked" {with_effector ("load_type" type(heavy)){with_effector}}
			else tagged "cwts_tank_linked" {with_effector {unlink_trailer} {components "transmission" break} {with_effector}}
			}
		else effector "tank medium_M"
			{if tagged "cwts_car_linked" {with_effector ("load_type" type(light)){with_effector}}
			else tagged "cwts_btr_linked" {with_effector ("load_type" type(light)){with_effector}}
			else tagged "cwts_bmp_linked" {with_effector ("load_type" type(normal)){with_effector}}
			else tagged "cwts_tank_linked" {with_effector ("load_type" type(heavy)){with_effector}}
			}
		else effector "tank heavy_M"
			{if tagged "cwts_car_linked" {with_effector ("load_type" type(light)){with_effector}}
			else tagged "cwts_btr_linked" {with_effector ("load_type" type(light)){with_effector}}
			else tagged "cwts_bmp_linked" {with_effector ("load_type" type(normal)){with_effector}}
			else tagged "cwts_tank_linked" {with_effector ("load_type" type(heavy)){with_effector}}
			}
	    }
	    {delay 0.1 {delete}}
	}
}