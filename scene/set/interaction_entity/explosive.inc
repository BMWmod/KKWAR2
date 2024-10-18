{"mine"
	{inflammation_time 3}
	{on spawn
		{volumes "body" disable all}
		{volumes "body1" disable all}
		{add_view "mined_view_own"		"mined_own"		"mined_view"}
		{add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		{add_view "mined_view_defused"	"defused"		"mined_view"}
		{add_view "mined_view_discovered"	"mined_discovered"		"mined_view"}
		{call "change_state"}
	}
	{on "_explosion"
		{volumes "body1" disable blast}
		{volumes "body" disable blast}
		{stuff_detonate}
	}
	{on "explosion"
		{if mined
			{call "_explosion"}
		}
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{volumes "body1" disable all}
			{volumes "body" enable select touch contact contact_ground blast}
			{bone show "string"}
			{bone show "string1"}
			{bone show "string2"}
			{volumes "detector" enable all}
		 else tagged "manual_install"
			{tags add "mine_planted"}
			{volumes "body1" disable all}
			{volumes "body" enable select touch contact contact_ground blast}
			{bone show "string"}
			{bone show "string1"}
			{bone show "string2"}
			{volumes "detector" enable all}
		else
			{tags remove "mine_planted"}
			{volumes "body" disable all}
			{volumes "body1" enable select touch contact contact_ground blast}
			{bone hide "string"}
			{bone hide "string1"}
			{bone hide "string2"}
			{volumes "detector" disable all}
		}
	}
	{on blast_hit
		{if min_energy 2.5
			{if not stuff "mine"
				{stuff_detonate}
			}
		}				
	}
	{on "check_terrain"
		{tags remove "mine_planted_road"}
		{tags remove "mine_planted_ground"}
		{if tagged "mine_planted"
			{if tagged "vis_none"
			else tagged "vis_25"  {if rand 0.25
				{if terrain_fx "road" {tags add "mine_planted_road"}
				else terrain_fx "country_road" {tags add "mine_planted_road"}
				else terrain_fx "ground" {tags add "mine_planted_ground"}
				}
			}
			else tagged "vis_50"  {if rand 0.5
				{if terrain_fx "road" {tags add "mine_planted_road"}
				else terrain_fx "country_road" {tags add "mine_planted_road"}
				else terrain_fx "ground" {tags add "mine_planted_ground"}
				}
			}
			else tagged "vis_75"  {if rand 0.75
				{if terrain_fx "road" {tags add "mine_planted_road"}
				else terrain_fx "country_road" {tags add "mine_planted_road"}
				else terrain_fx "ground" {tags add "mine_planted_ground"}
				}
			}
			else
				{if terrain_fx "road" {tags add "mine_planted_road"}
				else terrain_fx "country_road" {tags add "mine_planted_road"}
				else terrain_fx "ground" {tags add "mine_planted_ground"}
				}
			}
		}
	}
	{on "sp_spawn_obb"
		{spawn "obstacle_avoid_mine"}
		{tags remove "mine_planted_road"}
	}
	{on "undermine"
		{tags add "fuse"}
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{##delay 1
			{explosive 1}
		}
		{volumes enable touch}
		{##delay 8
			{call "explosion"}
		}
	}
	{on "break"
		{delete}
	}
}

{"kamikaze_bomb"
	{on blast_hit
		{if min_energy 0.5
			{stuff_detonate}
		}	
	}
}

{"mine_antipersonnel"
	{on contact
		{if mine_effector "human"
			{call "explosion"}
		else mine_effector "vehicle"
			{call "explosion"}
		else mine_effector "animal"
			{call "explosion"}
		}
	}
	(mod "mp"
		{on blast_hit
			{if min_energy 1.5
				{if not stuff "mine"
					{stuff_detonate}
				}
			}	
		}
	)
}
{"frogmine"
	{on spawn
		{volumes "body" disable all}
		{volumes "body1" disable all}
		{add_view "mined_view_own"		"mined_own"		"mined_view"}
		{add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		{add_view "mined_view_defused"	"defused"		"mined_view"}
		{call "change_state"}
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{volumes "body1" disable all}
			{volumes "body" enable select touch contact contact_ground blast}
		 else
			{tags remove "mine_planted"}
			{volumes "body" disable all}
			{volumes "body1" enable select touch contact contact_ground blast}
		}
	}
	{on contact
	  {if volume "body"
		{if mine_effector "human"
			{spawn "frogmine_jumper"}
			{stuff_detonate}
		else mine_effector "vehicle"
			{spawn "frogmine_jumper"}
			{stuff_detonate}
		else mine_effector "animal"
			{spawn "frogmine_jumper"}
			{stuff_detonate}
		}
	  }
	}
	{on blast_hit
		{if min_energy 3
			{if not stuff "mine"
				{stuff_detonate}
			}
		}	
	}
}
{"mine_manual_install"
	{on spawn
		{call "arm"}
		{physics_work 0}
	}
	{on "arm"
		{delay 3
			{tags add "armed"}
			{tags add "manual_install"}
			{call "change_state"}
		}	
	}
	{on "explosion"
		{call "_explosion"}
	}
}
{"frogmine_manual_install"	;only differences from frogmine
	{on spawn
		{delay 3
			{volumes "body1" enable select touch contact contact_ground blast}
			{volumes "body" enable select touch contact contact_ground blast}
			{player -1}
		}
	}
}
{"flashmine"
	{on spawn
		{volumes "body" disable all}
		{volumes "body1" disable all}
		{add_view "mined_view_own"		"mined_own"		"mined_view"}
		{add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		{add_view "mined_view_defused"	"defused"		"mined_view"}
		{call "change_state"}
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{volumes "body1" disable all}
			{volumes "body" enable select touch contact contact_ground blast}
		 else
			{tags remove "mine_planted"}
			{volumes "body" disable all}
			{volumes "body1" enable select touch contact contact_ground blast}
		}
	}
	{on "delay_exp"
		{delay 0.5 0.2	{call "explosion"}}
	}
	{on contact
	  {if volume "body"
		{if mine_effector "human"
			{spawn "flashmine_jumper"}
			{stuff_detonate}
		else mine_effector "vehicle"
			{spawn "flashmine_jumper"}
			{stuff_detonate}
		else mine_effector "animal"
			{spawn "flashmine_jumper"}
			{stuff_detonate}
		}
	  }
	}
	{on blast_hit
		{if min_energy 3
			{if not stuff "mine"
				{stuff_detonate}
			}
		}	
	}
}
{"flashmine_manual_install"	;only differences from flashmine
	{on spawn
		{delay 3
			{volumes "body1" enable select touch contact contact_ground blast}
			{volumes "body" enable select touch contact contact_ground blast}
			{player -1}
		}
	}
}
{"frogmine_jumper"
	{on spawn
		{impulse up 14 com}
		{delay 0.1
			{spawn "ex_grenade_big"}
			{stuff_detonate}
		}
	}
}
{"flashmine_jumper"
	{on spawn
		{link_sound "launch" "weapon/shot/bazooka_cw/smaw"}
		{play_sound "launch"}
		{impulse up 14 rnd_dir 3}
		{gravity 1.3}
		{tags add "flare"}
		{add_view "signal_rocket" "flare" "root"}
		{view start "flare"}
		{delay 15.5
			{delete}
		}
	}
	{on ground_hit
			{stuff_detonate}
	}
	{on contact
			{stuff_detonate}
	}
}


;===================================================
{"air_dropped_mine"
	{inflammation_time 3}
	{on spawn
		{volumes "body" disable all}
		{volumes "body" enable contact_ground}
		{delay 1 {volumes "body" enable all}}

	}
	{on "burn_volume"
		{delay 5 {call "explosion"}}
	}

	{on "explosion"
		{volumes "body" disable blast}
		{stuff_detonate}
	}
	{on ground_hit
		{delay 1 {tags add "mine_planted"}}
	}
	{on contact
	      {if not tagged "mine_planted"
		{delay 1 {tags add "mine_planted"}}
	      else
		{call "check_effector"}
	      }
	}
}

{"pfm-1"
	{on "check_effector"
		{call "explosion"}
	}
}

{"ptm-1"
	{on "check_effector"
		{if effector "vehicle"
		      {if terrain_fx "sand"			;из-за специфики детонатора на мягком грунте может не сработать
			{if rand 0.8 {call "explosion"}}
		      else terrain_fx "snow"
			{if rand 0.6 {call "explosion"}}
		      else terrain_fx "water"
			{if rand 0.4 {call "explosion"}}
		     else
			{call "explosion"}
		     }
		}
	}
	{on "explosion" overload
		{volumes "body" disable blast}
		{delay 0 {stuff_detonate}}
	}
}

;===================================================
{"mine_antitank"
	{on contact
		{if mine_effector "mine_exploder"
			{delay 0
				{call "explosion"}
			}
		else mine_effector "vehicle"
			{if mined
				{volumes disable contact}
				{delay 0.1
					{call "explosion"}
				}
			}
		}
	}
}
{"mine_antitank_tm89"
	{on "_explosion" overload
		{volumes disable all}
		{spawn "cw_cumulative_jetthrower_vert200"
			{delay 0 {manual_shot} {delay 0 {delete}} }
		}
		{delay 0.01 {stuff_detonate}}
	}
}
{"mine_antitank_m21"
	{on "_explosion" overload
		{volumes disable all}
		{spawn "cw_cumulative_jetthrower_vert150"
			{delay 0 {manual_shot} {delay 0 {delete}} }
		}
		{delay 0.01 {stuff_detonate}}
	}
}
{"mine_jumping"
	{on "explosion"
		{if mined
			{volumes disable contact blast}
			{call "_explosion"}
		}
	}
	{on "_explosion" overload
		{spawn "ex_bul_sm" "root" x}
		{delay 0.01{stuff_detonate}}
	}
}
{"mine_jumping_impactor"
	{on spawn
		{impulse up 14 com}
		{delay 0.1
			{stuff_detonate}
		}
	}
}
{"mine_antipersonnel_pob"	;ПОБ не срабатывает, если не может выпрыгнуть. Ногой не остановишь, но наехав техникой - да
	{on contact overload
		{if mine_effector "vehicle"
			{if volume "body" {volumes disable contact}
			else volume "body1" {volumes disable contact}
			else {inherited}
			}
		else {inherited}
		}
	}
	{on "_explosion"
		{spawn "mine_antipersonnel_pob_j" "root" x}
	}
}
{"mine_antipersonnel_ozm72"	;ПОБ не срабатывает, если не может выпрыгнуть. Ногой не остановишь, но наехав техникой - да
	{on "_explosion"
		{spawn "mine_antipersonnel_ozm72_j" "root" x}
	}
}
{"mine_directional"
	{on "_explosion" overload
		{volumes disable all}
		{spawn "blast_restrictor_apmine" "blast_dir" x}
		{spawn "trophy_shoot" "blast_dir" x}
		{delay 0.01{stuff_detonate}}
	}
	{on contact overload
		{if tagged "manual_install"
		{if  relation "enemy" or relation "neutral" {inherited}}
		else {inherited}
		}
	
	}
}
{"mine_signal"
	{on "_explosion" overload
		{volumes disable all}
		{spawn "flashmine_jumper" "root"}
		{stuff_detonate}
	}
}
{"mine_strikecore"
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{volumes "detector_ir1" enable contact}
			{volumes "det_seismo" enable contact}
		else tagged "manual_install" 
			{tags add "mine_planted"}
			{volumes "detector_ir1" enable contact}
			{if tagged "armed"{volumes "det_seismo" enable contact}}
		else
			{tags remove "mine_planted"}
			{volumes "detector_ir1" disable contact}
			{volumes "det_seismo" disable contact}
		}
	
	}
	{on contact overload
	 {if relation "enemy" or relation "neutral"
	  {if mined
		{if mine_effector "cannon" {if volume "det_seismo" {call "_explosion"}}
		else mine_effector "human" {if volume "det_seismo" {call "_explosion"}}
		else mine_effector "animal" {if volume "det_seismo" {call "_explosion"}}
		else mine_effector "vehicle" {call "_explosion"}}
	  else tagged "manual_install"
	  	{if effector "cannon" {if volume "det_seismo" {call "_explosion"}}
		else effector "human" {if volume "det_seismo" {call "_explosion"}}
		else effector "animal" {if volume "det_seismo" {call "_explosion"}}
		else effector "vehicle"	{call "_explosion"}}
	  }
	 }
	}
}
{"mine_antitank_tm83"
	{on spawn 
	  {if mined
		{bone show "box"}
	  else tagged "manual_install"
		{bone show "box"}
	  }
	}
	{on "_explosion" overload
		{volumes "detector_ir1" disable contact}
		{delay 0.1
			{spawn "tm83_core" "blast_dir" x
				{impulse up 0.1 forward 100 com}
			}
			{spawn "spbe-d_fire" "blast_dir" x}
			{delay 0.01 {stuff_detonate}}
		}
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{bone show "box"}
		else tagged "manual_install" 
			{tags add "mine_planted"}
			{bone show "box"}
		else
			{tags remove "mine_planted"}
			{bone hide "box"}
		}
	
	}
	{on "arm" overload
		{bone show "box"}
		{delay 30
			{tags add "armed"}
			{tags add "manual_install"}
			{call "change_state"}
		}	
	}
}	
{"tm83_core"
	{on spawn {delay 0.3 {delete}}}
}

{"mine_antitank_pktm1r"
	{on spawn 
	  {if mined
		{ani_wind "open" end}
	  }
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{volumes "det_seismo" enable contact}
			{ani_wind "open" end}
		else
			{tags remove "mine_planted"}
			{volumes "det_seismo" disable contact}
		}
	
	}
	{on contact overload
	  {if mined
		{if mine_effector "vehicle"
		  {if volume "det_seismo"
			{volumes "det_seismo" disable contact}
			{volumes "detector_ir1" enable contact}
			{ani_play "scan"}
			{ani_play "slope"}
			{delay 1.5 {ani_play "slope" -1}
				{volumes "det_seismo" enable contact}
				{volumes "detector_ir1" disable contact}
			}
		  else  volume "detector_ir1"
			{volumes disable contact}
			{spawn "spbe-d_fire" "foresight_fx" x}
		    {spawn "spbe_pktm1r" "foresight" x {impulse forward 15 up 25 com}}
		    {delete}
		  }
		}
	  }
	}
}



{"blast_restrictor"
	{on spawn
		{delay 0.1 {volumes disable all}{stuff_detonate}}
	}
}

{"dynamite"
	{on spawn
	  {delay 0.1 {if not tagged "fuse" {if tagged "mine_planted"
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
		{delay 8
			{call "explosion"}
		}
	  }}}
	}
	{on "undermine"
		{tags add "fuse"}
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
		{delay 5
			{call "explosion"}
		}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
;			{con "explosion"}
			{stuff_detonate}
		}
	}
}
{"c4_bomb"
	{on spawn
		{link_sound "c4_bomb"				"weapon/special/c4_bomb"			}
	  {delay 0.1 {if not tagged "fuse" {if tagged "mine_planted"
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
		{play_sound "c4_bomb"}
		{delay 1.7 {play_sound "c4_bomb"}}
		{delay 3.6 {play_sound "c4_bomb"}}
		{delay 8
			{call "explosion"}
		}
	  }}}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
;			{con "explosion"}
			{stuff_detonate}
		}
	}
}
{"vzriv_paket"
	;{on bullet_hit
	;	{call "explosion"}
	;}
	{on blast
		{if min_energy 0.3
			{call "explosion"}
		}
	}
	{on "explosion"
		{stuff_detonate}
	}
}
{"art_bomb"
	{on "explosion"
		{setup_stuff_activator}
		{stuff_detonate}
		{view stop "trace"}
	}
	{on spawn
		{setup_stuff_activator}
		{add_view "art_bomb_tail" "trace" "basis"}
		{add_view "art_bomb_tail2" "trace" "basis"}
		{view start "trace"}
		{start_sound "weapon/shot/artillery"}
		{impulse fz -50000 fx 25000 2500 rnd_dir 8 2 com}
		{delay 0.5
			{volumes enable contact}
		}
	}
	{on ground_hit
		{if min_speed 10
			{physics_work 0}
			{call "explosion"}
		}
	}
	{on contact
		{if min_speed 8
			{physics_work 0}
			{call "explosion"}
		}
	}
}
{"air_bomb"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{ani_play "start"}
		{delay 0.5
			{volumes enable contact}
		}
	}
	{on ground_hit
		{if min_speed 10
			{call "explosion"}
		}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"air_bomb_stuff"
	{on "explosion"
		{stuff_detonate}
	}
	{on break_armor
		{call "explosion"}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"artillery_explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{delay 0
			{start_sound "weapon/shot/artillery"}
			{delay 2
				{call "explosion"}
			}
		}
	}
}

{"explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{setup_stuff_activator}
		{call "explosion"}
	}
}
{"explosion_p"
	{on "explosion"
		{stuff_detonate}
	}
	{on "play_sound"
		{start_sound "weapon\shot\background\howitzer"}
        }
	{on spawn
		{setup_stuff_activator}
		{call "play_sound"}
		{add_view "rocket_smoke" "trace" "fx_t"}
		{delay 8.45
			{view start "trace"}
			{ani_play "strike"}
		}
		{delay 9
			{call "explosion"}
		}
	}
}
{"cw_fgassist"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{impulse up 1 com}
		{delay 0.1 {call "explosion"}}
	}
	{on contact {delete}}
}

{"explosive_barrel"
	{inflammation_time 3}
	{on spawn
		{set "explosioned" 0}
	}
	{on break_armor
		{if name "pierce"
			{if stuff_filled "fuel" 20 or tagged "barrel_ent"
				{call "explosion"}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			else stuff "shell"
				{call "break"}
			}
	else name "blast"
			{call "break"}
		}
	}
	{on contact
;		{if effector "vehicle"
;			{if effector_velocity 5
;				{call "break"}
;			}
;		}
	}
	{on "burn"
	  {if not flag "explosioned"
		{set "explosioned" 1}
		{call "break"}
	  }
	}
	{on "break"
	  {if not flag "explosioned"
		{set "explosioned" 1}
		{if stuff_filled "fuel" 20 or tagged "barrel_ent"
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	  }
	}
	{on "fire_dmg"
		{fire radius 10 time 3 heating 6}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
			{volumes disable bullet blast contact}
			{delay 1
				{volumes enable contact}
			}
			{blastwave c4 0.2 r0 4 r1 6}
			{call "fire_dmg"}
			{spawn "barrel_die_big"}
			{spawn "fire_shellhole"}
			{add_view "smoke_barrel" "smoke" "root"}
			{view start "smoke"}
			{impulse up 15 3 dir 3 1 cx 0 1 cy 0 1 com}
			{delay 25
				{view stop "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if flag "explosioned"
			{blastwave c4 2 r0 4 r1 6}
			{call "fire_dmg"}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}

{"balloon"
	{on break_armor
		{if name "pierce"
			{if rand 0.2
				{bullet_detonate}
				{if stuff_filled "fuel" 5
					{call "explosion"}
				}
			}
		}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
			{spawn "flamer_die"}
			{spawn "fire_molot_ground"}
			{blastwave c4 2 r0 1 r1 1.5}
			{fire radius 6 time 2 heating 6}
			{delete}
		}
	}
}

{"explosive_stuff"
	{inflammation_time 7}
	{on break_armor
		{call "explosion"}
	}
	{on "burn"
		{call "explosion"}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
;			{con "explosion"}
			{stuff_detonate}
		}
	}
}
