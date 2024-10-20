;-------------------------------------------=======================MAIN=============================
;by Pheonix
;---------------Main-------------
;=======================Vehicle_families=============================
(define "T72"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}		
		("rand_texmod_0")
	}
	("t72_sound")
	("2a46_type_gun")
)
(define "T80"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}			
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
		("rand_texmod_3" name1(summer) name2(green) name3(wood))
    }
	("t80_sound")
    	("2a46_type_gun_nogilz")
	{on fire "mgun" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun))
	}
	{on fire "mgun1" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun1))
	}
)
(define "bmp2"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel3"		"Foresight5"}
		{add_view	 	"BMP2_canon_fire"	"flashbarrel1"		"Foresight1"}
		("rand_texmod_1" name1(summer))
	}
	("bmp1_sound")
	{on fire "mgun" overload
		{view start "flashbarrel3"}
		("cw_check_shooting" weap_id(mgun))
	}
	("atgm_single_launcher" weapon(gun2) foresight(foresight6) tail(tail))
	("30mm_2a42")
)
(define "bmd"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel3"		"Foresight3"}
		{add_view	 	"flash_gun_big"	"flashbarrelu"		"Foresight5"}
		{add_view	 	"flash_gun_big"	"flashbarrelb"		"Foresight4"}
		("rand_texmod_3" name1(pole) name2(wood) name3(wood_brown))
   	}
	("bmd_sound")
	{on fire "mgun" overload
		{view start "flashbarrel3"}
		("cw_check_shooting" weap_id(mgun))
	}
	{on fire "mgun2" overload
		{view start "flashbarrelu"}
		("cw_check_shooting" weap_id(mgun2))
	}
	{on fire "mgun1" overload
		{view start "flashbarrelb"}
		("cw_check_shooting" weap_id(mgun1))
	}
	{on "emit_desant"
		{delay 0.1 {with_linked_entity "seat4"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat5"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
	}
)
(define "btr-d"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel3"		"Foresight3"}
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
		("rand_texmod_1" name1(wood))
   	}
	("bmd_sound")
	("small_multibarrel_gun" shooter(shooter) fxshell(fxshell))
	{on fire "mgun2" overload
		{view start "flashbarrel3"}
		("cw_check_shooting" weap_id(mgun2))
	}
	{on fire "mgun1" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun1))
	}
	("atgm_single_launcher" weapon(gun2) foresight(foresight6) tail(tail))
)
(define "Kliver_module"
	{on fire "mgun" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun))
	}
	("atgm_multi_launcher" weapon(gun2) foresight(foresight2) tail(tailr_))
	("30mm_2a72")
    	{on fire "mgun2" overload
		{spawn "startsmoke" inv_normal}
		("cw_check_shooting" weap_id(mgun2))
	}
)
;-------------------------------------------=======================End of defines=============================
{"t34-85_cw"
	("t34_sound")
    ("90-105mm_gun_with_cm")
	("no_gilza_ejection")
}
{"t-55"
	{on spawn		
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}	
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight5"}
	}
	("t62_sound")
    	("90-105mm_gun_with_cm")
	("no_gilza_ejection")
}

{"t62"
	{on spawn 		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
		("update_hatch" wind(true) place(charger))
	}
	{on fire "mgun1" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun1))
	}
	("t62_sound")
		("u5ts_type_gun")
	("update_hatch_event" event(operatable on) place(charger))
	("update_hatch_event" event(operatable off) place(charger))
	("update_hatch_event" event(crew in) place(charger))
	("update_hatch_event" event(crew out) place(charger))
	("zpu_params" gunner(charger) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy))

;	("commonzpu_params" gunner(charger) zpu_mgun(mgun) anim(into_hatch_common) pose(t62_zpy))
;	("zpu_one_hatch" gunner(charger) hatch_anim(open1))
}
{"t62md"
	{on spawn 		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
		("update_hatch" wind(true) place(charger))
	}
	{on fire "mgun1" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun1))
	}
	("t62m_sound")
    	("u5ts_type_gun")
	("update_hatch_event" event(operatable on) place(charger))
	("update_hatch_event" event(operatable off) place(charger))
	("update_hatch_event" event(crew in) place(charger))
	("update_hatch_event" event(crew out) place(charger))
	("zpu_params" gunner(charger) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy))
}
{"t64"
	("t64_sound")
    	("2a46_type_gun_nogilz")
}
{"t-64b"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight5"}
	}
	("t64_sound")
    	("2a46_type_gun_nogilz")
}
{"t-64bv"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight5"}
	}
	("t64_sound")
    	("2a46_type_gun_nogilz")
}
{"t-64bm1"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight5"}
	}
	("t64_sound")
    	("2a46_type_gun_nogilz")
}
{"t-64bm2"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight5"}
	}
	("t64_sound")
    	("2a46_type_gun_nogilz")
}
{"t72_cw"
	("T72")
;	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_gunner2))
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(commander))
	}
	("update_hatch_event" event(operatable on) place(commander))
	("update_hatch_event" event(operatable off) place(commander))
	("update_hatch_event" event(crew in) place(commander))
	("update_hatch_event" event(crew out) place(commander))
	("zpu_params" gunner(commander) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy))

}
{"t72_yral"
	{on "open_shield"	
	  {if not flag "radar_up" {ani_play "open_shield" 0.3}	{set "radar_up" 1}}
	}
	{on "close_shield"	
	       {if flag "radar_up" {ani_play "open_shield" -0.3} {set "radar_up" 0}}
	}
	{on move on	{kill_delay "anten"}			{call "close_shield"}}
	{on move off	{delay 5 "anten"			{call "open_shield"}}}
;	{on operatable off	{kill_delay "anten"}			{call "close_shield"}}
;	{on operatable on	{call "open_shield"}}
}



{"T72a_new"
	("T72")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy))
}
{"T72b_new"
	("T72")
	("zpu_params" gunner(charger) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy))
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(charger))
	}
	("update_hatch_event" event(operatable on) place(charger))
	("update_hatch_event" event(operatable off) place(charger))
	("update_hatch_event" event(crew in) place(charger))
	("update_hatch_event" event(crew out) place(charger))
}
{"t72_syria" 	
   {on "cut_parts"  
      (define "tear_sandbag"
	{tear "piece_medium_sand" bone "%0"   
		{impulse up 3 1 dir 3 1 cx 3 1 cy 3 1 rnd_dir 4 no_position}   
	} 
      )
	("tear_sandbag" args sandbag1) ("tear_sandbag" args sandbag2) ("tear_sandbag" args sandbag3)
	("tear_sandbag" args sandbag4) ("tear_sandbag" args sandbag5) ("tear_sandbag" args sandbag6)
	("tear_sandbag" args sandbag7) ("tear_sandbag" args sandbag8) ("tear_sandbag" args sandbag9)
	("tear_sandbag" args sandbag10) ("tear_sandbag" args sandbag11) ("tear_sandbag" args sandbag12)
	("tear_sandbag" args sandbag1) ("tear_sandbag" args sandbag2) ("tear_sandbag" args sandbag3)
	("tear_sandbag" args part13) ("tear_sandbag" args part14) ("tear_sandbag" args part15) 
	("tear_sandbag" args part16) ("tear_sandbag" args part17) ("tear_sandbag" args part18) 
	("tear_sandbag" args part19) ("tear_sandbag" args part20) ("tear_sandbag" args part21) 
	("tear_sandbag" args part22) ("tear_sandbag" args part23) 
         }
}
{"t72ba_gorod"
	("T72")
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy_gorod))
}
{"t72ba"
	("t90_sound")
}
{"t72b3_2017"
	("t90_sound")
}
{"t72b3_2017_2"
	("t90_sound")
}
{"t72b3_gorod_komplect"
	("t90_sound")
}
{"t80b_series"
	("T80")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(t80b_mgunner))
}
{"t80u_series"
	("T80")
	("update_hatch_event" event(operatable on) place(charger))
	("update_hatch_event" event(operatable off) place(charger))
	("update_hatch_event" event(crew in) place(charger))
	("update_hatch_event" event(crew out) place(charger))
	("zpu_params" gunner(charger) zpu_mgun(mgun) anim(into_hatch_common) pose(t80y_mgunner))
}
{"t80ye-1"
	("T80")
}

{"bm_oplot"
	("t64_sound")	;сюда надо свой комплект звуков
    ("2a46_type_gun_nogilz")
	{on fire "mgun1" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun1))
	}
	{on fire "mgun" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun))
	}
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))
	{on break overload
		{if component "apu"
			{if not tagged "destroyed"
				{damage_report "apu" "apu_damaged"}
				{spawn "metal_hit_bul"}
			}
			{tags add "apu_damaged"}
			{call "update_power"}
			{delay 0.1 {call "update_turret"}}
			{if rand 0.15
				{burn fx "smoke_dead_norm" fake}
			}
		else {inherited}
		}
		{call "update_lights"}
		{call "update_moveability"}
	}
}
{"t-90a"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}			
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
		{add_view	 	"flash_gun_big"	"flashbarrel2m"		"Foresight2"}
		("rand_texmod_0")
    }
	("t90_sound")
    	("2a46_type_gun")
	{on fire "mgun" overload
		{view start "flashbarrel2m"}
		("cw_check_shooting" weap_id(mgun))
	}
	{on fire "mgun1" overload
		{view start "flashbarrel4"}
		{spawn "mgun_smoke" "Foresight4" x}  
		("cw_check_shooting" weap_id(mgun1))
	}
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))
}
{"bmr-3"
	("t90_sound")
	{on fire "mgun" overload
		("cw_check_shooting" weap_id(mgun))
	}
}
{"t90sm"
	{on spawn
		("rand_texmod_1" name1(wood))
	}
	("t90_sound")
	{on "init_gun"	;Обычный макрос для 2А46, прост овышел косяк с выбросом поддона.
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
	}
	("110-130mm_gun_with_cm")
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "poddon_cannon" "turret_systems" x scale 1
			{impulse up -1 0.7 dir -1 0.7 cz 0.2 0.1 forward 8 0.5 com}
			{delay 6 2.5 {hide 3}}
		}
	}
	{on fire "mgun" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun))
	}
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))
	{on break overload
		{if component "apu"
			{if not tagged "destroyed"
				{damage_report "apu" "apu_damaged"}
				{spawn "metal_hit_bul"}
			}
			{tags add "apu_damaged"}
			{call "update_power"}
			{delay 0.1 {call "update_turret"}}
			{if rand 0.15
				{burn fx "smoke_dead_norm" fake}
			}
		else {inherited}
		}
		{call "update_lights"}
		{call "update_moveability"}
	}
}
{"t-14"
	{on spawn
		("rand_texmod_1" name1(camo1))
	}
	("t14_sound")
	("110-130mm_gun_with_cm")
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "poddon_cannon_side" "turret_systems" x scale 1
			{impulse up 0 0.1 dir -1 0.7 cz 0.2 0.1 forward 8 0.5 com}
			{delay 6 2.5 {hide 3}}
		}
	}
	{on fire "mgun" overload
		{view start "flashbarrel3"}
		("cw_check_shooting" weap_id(mgun))
	}
	("afganit_smoke_mortar" mgun_id(20) side(l))
	("afganit_smoke_mortar" mgun_id(21) side(r))
	{on "ammo_burnout" overload
		{call "blow_burnout"}
		{start_sound "detonation/ammo_burnout"}
		{spawn "ex_air_big"}
	}
	{on "blow_burnout"
		{delay_ex 0
			{start_sound "detonation/ammo_burnout"}
			{burn volume "ammo_storage_main" fx "burnout_blow_panel1" time 10 fake}
			{delay 1.4 0.4 {burn volume "ammo_storage_main" fx "burnout_blow_panel2" time 10 fake}}
			{delay 1 1 {burn volume "ammo_storage_main" fx "burnout_blow_panel3" time 10 fake}}
			{delay 5 1 {burn volume "ammo_storage_main" fx "burnout_blow_panel4" time 15 fake}}
			{components "turret" break}
			{components "turret_move_engine" break}
			{components "autoloader" break}
			{components "autoloader" break}
		}
		
	}
	{on "_explosion"
		{tear "piece_medium_steel" bone "part7" {impulse up 5 rnd_dir 2}}
	}
	{on break overload
		{if component "apu"
			{if not tagged "destroyed"
				{damage_report "apu" "apu_damaged"}
				{spawn "metal_hit_bul"}
			}
			{tags add "apu_damaged"}
			{call "update_power"}
			{delay 0.1 {call "update_turret"}}
			{if rand 0.15
				{burn fx "smoke_dead_norm" fake}
			}
		else component "fuel_tank_internal_a"
		{if not tagged "destroyed"
			{damage_report "fuel_tank_external_a" "fuel:fuel_tank_damaged"}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 4 time 1 heating 3}
				{call "_burn"}
				{if rand 0.8
					{spawn "ex_air_big"}
				}
			}
		}
		else {inherited}
		}
		{if volume "ammo_storage_main"
				{tear "piece_medium_steel" bone "part7" {impulse up 5 rnd_dir 2}}
		}
		{call "update_lights"}
		{call "update_moveability"}
	}
	{on "sink"
		{tags add "sunken"}
	}
}
{"t15barbaris"
	{on spawn
		("rand_texmod_1" name1(camo))
	}
	("t14_sound")
	
	{on "ammo_burnout" overload
		{call "blow_burnout"}
		{start_sound "detonation/ammo_burnout"}
		{spawn "ex_air_big"}
	}
	{on "blow_burnout"
		{delay_ex 0
			{start_sound "detonation/ammo_burnout"}
			{burn volume "ammo_storage_autocannon1" fx "burnout_ifv1" time 10 fake}
			{delay 1.4 0.4 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv2" time 10 fake}}
			{delay 1 1 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv3" time 10 fake}}
			{delay 5 1 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv4" time 15 fake}}
			{components "turret" break}
			{components "turret_move_engine" break}
			{components "gun" break}
			{components "mgun" break}
		}
	}

;	{on fire "mgun" overload
;		{view start "flashbarrel3"}
;		("cw_check_shooting" weap_id(mgun))
;	}
	("afganit_smoke_mortar" mgun_id(20) side(l))
	("afganit_smoke_mortar" mgun_id(21) side(r))
	{on break overload
		{if component "apu"
			{if not tagged "destroyed"
				{damage_report "apu" "apu_damaged"}
				{spawn "metal_hit_bul"}
			}
			{tags add "apu_damaged"}
			{call "update_power"}
			{delay 0.1 {call "update_turret"}}
			{if rand 0.15
				{burn fx "smoke_dead_norm" fake}
			}
		else {inherited}
		}
		{if volume "ammo_storage_main"
				{tear "piece_medium_steel" bone "part7" {impulse up 5 rnd_dir 2}}
		}
		{call "update_lights"}
		{call "update_moveability"}
	}
	{on "sink"
		{tags add "sunken"}
	}
}
{"t-15"
	("30mm_2a42")
	("atgm_multi_launcher" weapon(gun2) foresight(foresight4) tail(tailL_))
	("atgm_multi_launcher" weapon(gun3) foresight(foresight5) tail(tailR_))
}

{"t-15_au220"
	("autocannon")
	("25-50mm_gilza" fxshell(FXshell_canon))
	("atgm_multi_launcher" weapon(gun3) foresight(foresight4) tail(tailR_))
}



{ "Msta"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}	
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
		{add_view "zenit_gilz"		"shell_m1"	"fxshell"}	
		("rand_texmod_1" name1(wood))
   	}
	("msta_sound")
    	("135-180mm_sph_gun")
	("135-180mm_gilza_forward")
	{on fire "mgun" 
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
		
	}
	("smokegun_nospread" smokegun(mgun18))
	("smokegun_nospread" smokegun(mgun19))
}
{ "2c3_akaciya"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}	
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
		("rand_texmod_1" name1(wood))
	}
	("bmp1_sound")
    	("135-180mm_sph_gun")
	("135-180mm_gilza")
}
{ "koalition"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}	
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
		("rand_texmod_1" name1(woodland))
	}
 	("t90_sound")
   	("135-180mm_sph_gun")
	{on fire "mgun" 
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
		
	}
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))
}
{"2s7"
	{on spawn
		("rand_texmod_1" name1(camo))
		{add_view 	"dust_shot_big_link"		"flashbarrel1"			"basis"}
		{add_view 	"dust_shot_big_link"		"flashbarrel1"			"dirt1"}
		{add_view 	"dust_shot_big_link"		"flashbarrel1"			"dirt4"}
		{add_view 	"canon_gaub_fire_link"		"flashbarrel1"			"dirt4"}
	}
	("t72_sound")
    {on fire "gun" 
		("tank_gun")
;      	{spawn "dust_shot_big" "basis"}
;      	{spawn "dust_shot_big" "dirt1"}
;      	{spawn "dust_shot_big" "dirt4"}
;    	{spawn "canon_gaub_fire" "Foresight1" x}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
		(define "otval_fx"
;turn on after fog of war fix
;			{spawn "%fx" "dirt1"}{spawn "%fx" "dirt2"}{spawn "%fx" "dirt3"}{spawn "%fx" "dirt4"}
		)
		{if terrain_fx "snow"	("otval_fx" fx(snow_hit_big))
		else terrain_fx "sand"	("otval_fx" fx(sand_hit_big))
		else terrain_fx "shallow_water"	("otval_fx" fx(spherewater_big))
		else terrain_fx "water"	("otval_fx" fx(spherewater_big))
		else terrain_fx "deep_water"	("otval_fx" fx(spherewater_big))
		else terrain_fx "puddle"	("otval_fx" fx(stone_hit_small))
		else ("otval_fx" fx(stone_hit_small))
		}
		
		{if crew_in_place "driver" {ani_stop "fire"}}
		{delay 1 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 2 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 3 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 4 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 5 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 6 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 7 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 8 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 9 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 10 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 11 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 12 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 13 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 14 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 15 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 16 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 17 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 18 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 19 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 20 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 21 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 22 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 23 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 24 {if crew_in_place "driver" {ani_stop "fire"}}}
		{delay 25 {if crew_in_place "driver" {ani_stop "fire"}}}
	}
	{on move on
		{ani_stop "fire"}
	}


}
{"mtlb"
	{on spawn
		("rand_texmod_2" name1(newcom) name2(newcom2))
	}
	("mtlb_sound")
}
{"mtlb_vmk"
	("mtlb_sound")
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
    }
	{on fire "mgun" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun))
	}
}
{"mtlb_noammobox"
	{on spawn
		{delay 0.1
			{if crew_in_place "seat1"
				{ani_wind "open_desant_cover1" end}
			else
				{ani_wind "open_desant_cover1" begin}
			}
			{if crew_in_place "seat2"
				{ani_wind "open_desant_cover2" end}
			else
				{ani_wind "open_desant_cover2" begin}
			}
		}
	}
}	
	
	
{"mtlb_6ma"
	("mtlb_sound")
	("14_7mm_kpvt")
	("smokegun_nospread" smokegun(mgun17))
}
{"mtlb_6mb"
	("mtlb_sound")
	("30mm_2a72")
	("smokegun_nospread" smokegun(mgun17))
	("smokegun_nospread" smokegun(mgun18))
}
{"9p149_shturm-s"
	{on spawn
		("rand_texmod_0")
	}
	{on operatable on
		{if not flag "started"
			{set "started" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on repair
		{if component "body"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on "init_gun2"
		{set "radar_up" 0}
		{add_view	"rok_tail"	"rok_tail_gun2"	"tail01"}
		{add_view 	"startsmoke_link"		"rok_tail_gun2"			"foresight1"}
		{add_view 	"startsmoke_link"		"rok_tail_gun2"			"tail01"}
	}
	{on fire "gun2" overload
		{delay 0.5 {ik_enable "turret" 0} {set "radar_up" 1}}
		{delay 14.5 {set "radar_up" 0}{call "update_turret"}}
		("low_speed_bullet")
		{ani_play "fire"}
		{view start "rok_tail_gun2"}
;		{spawn "startsmoke" "foresight1" x}
;		{spawn "startsmoke" "tail01" x}
		{set "gun2"}{call "proj_probe"}
		{delay 0.4 {view pause "rok_tail_gun2"}}
		("cw_check_shooting" weap_id(gun2))
		{delay 0.1 {call "spawn_shell"}}
		{volumes "gun_recoil" enable blast}
		{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
		{delay 0.5 {volumes "gun_recoil" disable blast}}
	}
	{on "update_turret" overload
		{if flag "radar_up" {ik_enable "turret" 0}
		else {inherited}
		}
	}
	{on "spawn_shell" 
		{spawn "tpk_shturm_s" "shell_up" x
			{impulse up 0.2 0.1 dir 0.2 0.1 cz 0.2 0.1 forward 0.7 0.2 com}
			{delay 6 2.5 {hide 3}}
		}
	}
}
{"strela10"
	{on spawn
		("rand_texmod_0")
	}
	("mtlb_sound")	
	{on operatable on
		{if not flag "radar_up"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on repair
		{if component "body"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on ik begin "turret" {play_sound "rotate_turret" 1}}
	{on ik end "turret" {stop_sound "rotate_turret"}}
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight2) tail(tail_) shooter(shooter))
	{on bullet_hit
		{if volume "glass" {call "break_glass"}}
	}
	{on "break_glass"
		{volumes "glass" disable bullet contact}
	 	{spawn "glass_hit2" "glass" x}
	 	{delay 0.1 {bone cut "glass"}}
	}
}
{"bmp1"
	{on spawn
		("rand_texmod_2" name1(camo) name2(far5))
	}
	("bmp1_sound")
    	("73mm_2a28_grom")
	("custom_single_launcher" weapon(gun2) foresight(foresight2) missile(9k14m) tail(none))
}
{"bmp2d"
	("bmp2")
}
{"bmp2"
	("bmp2")
}

{"bmp2m"
	{on spawn		
		{add_view	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
    	}
	("bmp1_sound")
    	("30mm_2a42")
	{on fire "mgun" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun))
	}
    	("auto_gren_launcher" mgun(mgun2))
	("atgm_multi_launcher" weapon(gun2) foresight(foresight2) tail(tailR_))
	("atgm_multi_launcher" weapon(gun3) foresight(foresight3) tail(tailL_))
}
{"bmp3_common"
	{on spawn		
		{add_view 	"flash_zenit"	"flashbarrel2"		"foresight6"}
		("rand_texmod_2" name1(green) name2(summer))
    }
	("bmp3_sound")
	("100mm_2a70")
	("90-105mm_gilza")
	("30mm_2a42_gun1")
	{on "gunner_hatch_open" overload}
	;gun can be disabled by specability
	{on "update_gun"
		{if work "gun"
			 {if work "stabilizer"
			   {if work "gunner_panel"
				{if not flag "specability"
				  {if not tagged "contusion"
					{if not tagged "cw_autoloader_stuck"
						{weapon_work "gun" 1}
					else {weapon_work "gun" 0}}
				  else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			   else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
	{on "emit_desant"
		{delay 0.1 {with_linked_entity "seat10"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat11"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat12"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat13"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
	}
}
{"bmp3_dz"
;	("90-105mm_gilza")
}
{"bmp3_derivation"
	("bmp3_sound")
}
{"kurganec"
	{on spawn
		("rand_texmod_3" name1(camo))
	}
	("kurganec_sound")
	{on "cut_parts"
		{if rand 0.5 ("cut_part" args "door")}
	}
}
{"kurganec_b-11"
	("30mm_2a42")
	("atgm_multi_launcher" weapon(gun2) foresight(foresight4) tail(tailL_))
	("atgm_multi_launcher" weapon(gun3) foresight(foresight5) tail(tailR_))
	{on "ammo_burnout" overload
		{call "blow_burnout"}
		{start_sound "detonation/ammo_burnout"}
		{spawn "ex_air_big"}
	}
	{on "blow_burnout"
		{delay_ex 0
			{start_sound "detonation/ammo_burnout"}
			{burn volume "ammo_storage_autocannon1" fx "burnout_ifv1" time 10 fake}
			{delay 1.4 0.4 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv2" time 10 fake}}
			{delay 1 1 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv3" time 10 fake}}
			{delay 5 1 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv4" time 15 fake}}
			{components "turret" break}
			{components "turret_move_engine" break}
			{components "gun" break}
			{components "mgun" break}
		}
	}
}
{"uran9"
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))		
	("uran9_sound")
	("30mm_2a72")
	{on "uprise_anten"	
	    {if not flag "idle" 
			{set "idle" 1}
			{ani_stop "launcher"}
			{ani_play "launcher" 1 callback}
			{play_sound "rotate_turret" 1}			
	    }
	}
	{on animation_end "launcher"
		{set "radar_up" 1}
		{call "update_gun23"}
		{stop_sound "rotate_turret"}
	}
	{on "lower_anten"	
	    {if flag "idle" 
			{ani_stop "launcher"}
			{ani_play "launcher" -1}
			{set "radar_up" 0}
			{set "idle" 0}
			{call "update_gun23"}
			{stop_sound "rotate_turret"}
	    }
	}
;	{on "update_gun23" overload
;		{if not flag "radar_up" 
;			{weapon_work "gun2" 0}
;			{weapon_work "gun3" 0}
;		else {inherited}
;		}
;	}
	{on ik begin "pilonl_rot"
		{kill_delay "rotate_turret"}
		{if not flag "rotate_turret"
			{play_sound "rotate_turret" 1}
			{set "rotate_turret" 1}
		}
	}
	{on ik end "pilonl_rot"
		{delay 0.5 "rotate_turret"
			{stop_sound "rotate_turret"}
			{set "rotate_turret" 0}
		}
	}
	{on "update_cw_panorama" overload
	   {if operatable
		{if work "additional_triplex"
			 {if work "commander_triplex"
				  {if not tagged "contusion"
						{if not tagged "no_power"
							{call "cw_panorama_work"}
						else {call "cw_panorama_off"}}
				  else {call "cw_panorama_off"}}
			 else {call "cw_panorama_off"}}
		else {call "cw_panorama_off"}}
	   else {call "cw_panorama_instant_off"}}
	}
	{on move on	{kill_delay "anten"}			{call "lower_anten"}}
	{on move off	{delay 1 "anten"			{call "uprise_anten"}}}
	{on operatable off	{kill_delay "anten"}			{call "lower_anten"}}
	{on operatable on	{call "uprise_anten"}}
	{on "sink"
		{player -1} {weapon_work "gun" 0} {weapon_work "mgun" 0} 
		{weapon_work "gun2" 0}{weapon_work "gun3" 0}
		{able "select" 0} {able "repaired" 0} 
;		{able "minimap" 0}	;Отключено в MOW2
		{volumes disable touch select}
	}
	{on "mp_destroy"
;		{player -1} 
;		{weapon_work "gun" 0} {weapon_work "mgun" 0} 
;		{weapon_work "gun2" 0}{weapon_work "gun3" 0}
;		{able "select" 0} {able "repaired" 0} {able "minimap" 0}
;		{volumes disable touch select}
	}

}
{"uran9_assault"
	{on fire "gun3"
		{spawn "bazooka_shot"}
		{spawn "rpo_m_tube"
			{impulse forward -10 0.4}
		}
		("cw_check_shooting" weap_id(gun3))
	}
}
{"uran9_assault2"
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight4) tail(tail_ataka) shooter(shooter_ataka))
	{on fire "gun3"
		{spawn "bazooka_shot"}
		{spawn "rpo_m_tube"
			{impulse forward -10 0.4}
		}
		("cw_check_shooting" weap_id(gun3))
	}
}
{"uran9_support"
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight4) tail(tail_ataka) shooter(shooter_ataka))
	("custom_multi_launcher"	weapon(gun3) tail(tail_igla) shooter(shooter_igla) missile(igla_s))
}
{"bmd1"
	("bmd")
	("73mm_2a28_grom")
	("custom_single_launcher" weapon(gun2) foresight(foresight2) missile(9k14m) tail(none))
}
{"bmd1p"
	("bmd")
	("73mm_2a28_grom")
	("atgm_single_launcher" weapon(gun2) foresight(foresight6) tail(tail))
}
{"bmd2"
	("bmd")
	("30mm_2a42")
	("atgm_single_launcher" weapon(gun2) foresight(foresight6) tail(tail))
}
{"2c9"
	("bmd")
    {on fire "gun" 
		{set "gun"}{call "proj_probe"}
	}
}
{"bmd4m"
	{on spawn		
		{add_view 	"flash_zenit"	"flashbarrel2"		"foresight6"}
		("rand_texmod_1" name1(camo))
	}
	("bmd4m_sound")
	("100mm_2a70")
	("90-105mm_gilza")
	("30mm_2a42_gun1")
	{on "gunner_hatch_open" overload}
	;gun can be disabled by specability
	{on "update_gun"
		{if work "gun"
			 {if work "stabilizer"
			   {if work "gunner_panel"
				{if not flag "specability"
				  {if not tagged "contusion"
					{if not tagged "cw_autoloader_stuck"
						{weapon_work "gun" 1}
					else {weapon_work "gun" 0}}
				  else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			   else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
	{on "emit_desant"
		{delay 0.1 {with_linked_entity "seat10"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat11"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat12"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat13"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
	}
}
{"brdm2"
	("brdm_sound")	
	("14_7mm_kpvt")
}
{"brdm2_strela"
	("brdm_sound")	
	{on ik begin "turret" {play_sound "rotate_turret" 1}}
	{on ik end "turret" {stop_sound "rotate_turret"}}
	{on spawn
		{add_view 	"startsmoke_link"		"tail00"			"shooter00"}
		{add_view 	"startsmoke_link"		"tail01"			"shooter01"}
		{add_view 	"startsmoke_link"		"tail02"			"shooter02"}
		{add_view 	"startsmoke_link"		"tail03"			"shooter03"}
	}
	{on fire "gun2" 
		("low_speed_bullet")
		{if name "00"	{delay 0.1 {spawn "9k31_carrier" "shooter00"   x}
;		{spawn "startsmoke" "shooter00" x}
		{view start "shooter00"}
		{delay 0.4 {view pause "shooter00"}}
		}
		else name "01"	{delay 0.1 {spawn "9k31_carrier" "shooter01"   x}
;		{spawn "startsmoke" "shooter01" x}
		{view start "shooter01"}
		{delay 0.4 {view pause "shooter01"}}
		}
		else name "02"	{delay 0.1 {spawn "9k31_carrier" "shooter02"   x}
;		{spawn "startsmoke" "shooter02" x}
		{view start "shooter02"}
		{delay 0.4 {view pause "shooter02"}}
		}
		else name "03"	{delay 0.1 {spawn "9k31_carrier" "shooter03"   x}
;		{spawn "startsmoke" "shooter03" x}
		{view start "shooter03"}
		{delay 0.4 {view pause "shooter03"}}
		}
		}
		{ani_play "fire"}
	}
	{on bullet_hit
		{if volume "glass" {call "break_glass"}}
	}
	{on "break_glass"
		{volumes "glass" disable bullet contact}
	 	{spawn "glass_hit2" "glass" x}
	 	{delay 0.1 {bone cut "glass"}}
	}
}
{"brdm2_atgm"
	("brdm_sound")	
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight) tail(tail) shooter(shooter_))
	{on operatable on
		{if not flag "radar_up"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on repair
		{if component "body"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on ik begin "turret" {play_sound "rotate_turret" 1}}
	{on ik end "turret" {stop_sound "rotate_turret"}}
}
{"kamaz_43269"
	("btr80_sound")	
}
{"btr60"
	("btr60_sound")	
	("14_7mm_kpvt")
}
{"btr70"
	("btr60_sound")	
	("14_7mm_kpvt")
}
{"btr80"
	{on spawn
		("rand_texmod_2" name1(summer) name2(summer2))
	}
	("btr80_sound")	
	("14_7mm_kpvt")
	("smokegun_nospread" smokegun(mgun17))
}
{"btr80a"
	{on spawn
		("rand_texmod_2" name1(summer) name2(summer2))
	}
	("btr80_sound")	
	("30mm_2a72")
	("smokegun_nospread" smokegun(mgun17))
	("smokegun_nospread" smokegun(mgun18))
}
{"btr82a_mgun"
	{on spawn
		("rand_texmod_2" name1(summer) name2(summer2))
	}
	("btr80_sound")	
	("14_7mm_kpvt")
	("smokegun_nospread" smokegun(mgun17))
	("smokegun_nospread" smokegun(mgun18))
}
{"btr82a"
	{on spawn
		("rand_texmod_2" name1(summer) name2(summer2))
	}
	("btr80_sound")	
	("30mm_2a72")
	("smokegun_nospread" smokegun(mgun17))
	("smokegun_nospread" smokegun(mgun18))
}

{"btr90"
	{on spawn		
		{add_view 	"smoke_zenit" 	"zenite_smoke2" 		"tail"}
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
    }
	("btr90_sound")
	{on fire "mgun" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun))
	}
	("atgm_single_launcher" weapon(gun2) foresight(foresight2) tail(tail))
    	("30mm_2a42")
    	("auto_gren_launcher" mgun(gun1))
	("smokegun_nospread" smokegun(mgun17))
	("smokegun_nospread" smokegun(mgun18))
}
{"btr90_kom"
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_btr90) pose(seat_m7_mgunner))
	{on "uprise_anten"	
	       {if not flag "radar_up" 
		{ani_play "close_anten" -0.3}	
		{set "radar_up" 1}
	        }
	}
	{on "lower_anten"	
	       {if flag "radar_up" 
		{ani_play "close_anten" 0.3}
		{set "radar_up" 0}
	       }
	}
	{on move on	{kill_delay "anten"}			{call "lower_anten"}}
	{on move off	{delay 5 "anten"			{call "uprise_anten"}}}
	{on operatable off	{kill_delay "anten"}			{call "lower_anten"}}
	{on operatable on	{call "uprise_anten"}}
	{on "mp_destroy"
		{volumes "part" enable contact_ground}
		(define "cut_part"
			{if rand 0.5
				{tear "piece_medium_steel" bone %0
					{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
					{delay_effect 20 5 "stop"}
				}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
	}
	("smokegun_nospread" smokegun(mgun17))
	("smokegun_nospread" smokegun(mgun18))
}
{"bumerang"
	{on spawn
		("rand_texmod_1" name1(camo))
	}
	("bumerang_sound")
;	("shtora_smoke_mortar" mgun_id(18))
;	("shtora_smoke_mortar" mgun_id(19))
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))
}
{"bumerang_k-17"
	("30mm_2a42")
	("atgm_multi_launcher" weapon(gun2) foresight(foresight4) tail(tailL_))
	("atgm_multi_launcher" weapon(gun3) foresight(foresight5) tail(tailR_))
	{on "ammo_burnout" overload
		{call "blow_burnout"}
		{start_sound "detonation/ammo_burnout"}
		{spawn "ex_air_big"}
	}
	{on "blow_burnout"
		{delay_ex 0
			{start_sound "detonation/ammo_burnout"}
			{burn volume "ammo_storage_autocannon1" fx "burnout_ifv1" time 10 fake}
			{delay 1.4 0.4 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv2" time 10 fake}}
			{delay 1 1 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv3" time 10 fake}}
			{delay 5 1 {burn volume "ammo_storage_autocannon1" fx "burnout_ifv4" time 15 fake}}
			{components "turret" break}
			{components "turret_move_engine" break}
			{components "gun" break}
			{components "mgun" break}
		}
	}
}

{"Shilka"
	{on spawn
		("rand_texmod_0")
	}
	("shilka_sound")
;	{on operatable on	{ani_play "radar" loop}}
;	{on operatable off	{delay 1	{ani_stop "radar"}}}
	("small_multibarrel_gun" shooter(shooter) fxshell(fxshell))
	("radar_params" triplex(commander_triplex) visor(visor1) anim_rotate(radar) marker(antirad_generator_rus))
}
{"9k72_common"	;SCUD
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}	
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view		"stop_signal"	"stop_signal"		"FXstop3"}	
		{view hide "stop_signal"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1s"			"basis"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1s"			"turret"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1s"			"opora1"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1s"			"opora2"}
		{add_view	"startsmoke_otrk_link"		"flashbarrel1s"			"turret"}
    }
	("9k72_sound")
    	{on fire "gun" 
;      		{spawn "dust_shot_big_2" "basis"}
;      		{spawn "dust_shot_big_2" "turret"}
;      		{spawn "dust_shot_big_2" "opora1"}
;      		{spawn "dust_shot_big_2" "opora2"}
;      		{spawn "startsmoke_otrk" "turret"}
			{view start "flashbarrel1s"}
			{delay 0.4
				{view pause "flashbarrel1s"}
			}
		{Volumes "ammo_storage_main" disable contact bullet blast}
		{delay 300 {Volumes "ammo_storage_main" enable contact bullet blast}}
	}
	{on break_armor
		{if volume "cabinl1" {components "cabinl" break} 
		else volume "cabinl2" {components "cabinl" break} 
		else volume "cabinr1" {components "cabinr" break} 
		else volume "cabinr2" {components "cabinr" break} 
		else volume "rubka" {components "rubka" break} 
		else volume "rubka1" {components "rubka" break} 
		else volume "rubka2" {components "rubka" break} 
		else volume "telo1" {components "telo1" break} 
		else volume "telo2" {components "telo2" break} 
		else volume "telo2_1" {components "telo2" break} 
		else volume "telo2_2" {components "telo2" break} 
		else volume "telo2_3" {components "telo2" break} 
		}
	}
	{on pierce
		{if component "ammo_storage_main"
			{spawn "ex_anti_size5" "launch_table"}
			{if not terrain_fx "bridge"	
			        {if not terrain_fx "bridge_wood"
				{spawn "crater_norm_land_size5" "basis" terrain_texmod}
			        }
			}
			{spawn "r17" "launch_table" x {stuff_detonate}}
			{call "_explosion"}
		}
	}
	{on bullet_hit
		(define "check_break_glass"
		     else volume "glass_%0"
			{volumes "glass_%0" disable bullet contact blast}
	 		{spawn "glass_hit2" "glass_%0" x}
	 		{delay 0.1
			 	{bone cut "glass_%0"}
	 		}
		)
		{if stuff "radar_ammo"	;чтобы не бить стекла лазерами и радарами
		else stuff "laser_ammo"
		else stuff "rus_IR_ff_beam ammo"
		else stuff "usa_IR_ff_beam ammo"
		else stuff "IR_ff_ammo"
		("check_break_glass" args l1)
		("check_break_glass" args l2)
		("check_break_glass" args l3)
		("check_break_glass" args l4)
		("check_break_glass" args r1)
		("check_break_glass" args r2)
		("check_break_glass" args r3)
		("check_break_glass" args r4)
		("check_break_glass" args f1)
		("check_break_glass" args f2)
		}
	}
	{on break 
		{if component "cabinl"  {spawn "tank_die_particle" "cabinl"}
		else component "cabinr" {spawn "tank_die_particle" "cabinr"}
		else component "rubka" {spawn "tank_die_particle" "rubka"}
		else component "telo1" {spawn "tank_die_particle" "telo1"}
		else component "telo2" {spawn "tank_die_particle" "telo2"}
		}
	}
	{on repair 
		{if component "cabinl"
		else component "cabinr"
		else component "rubka"
		else component "telo1"
		else component "telo2"
		}
	}
}
{"9k72"
	{on pierce
		{if component "ammo_storage_main"
			{spawn "ex_anti_size5" "launch_table"}
			{if not terrain_fx "bridge"	
			        {if not terrain_fx "bridge_wood"
				{spawn "crater_norm_land_size5" "launch_table" terrain_texmod}
			        }
			}
			{spawn "r17" "launch_table" x {stuff_detonate}}
			{call "_explosion"}
		}
	}
}
{"9k72_for_single"
	{on pierce overload
		{if component "ammo_storage_main"
			{call "_explosion"}
		else {inherited}
		}
	}
	{on "single_gren_exp_in_cab"
		{spawn "ex_air_big" "Cabinl"}
		{components "driver_panel" break }
		{components "cabinl" break }
		(define "break_glass"
			{volumes "glass_%0" disable bullet contact blast}
	 		{spawn "glass_hit2" "glass_%0" x}
	 		{delay 0.1 {bone cut "glass_%0"}}
		)
		("break_glass" args l1)
		("break_glass" args l2)
		("break_glass" args l3)
		("break_glass" args l4)
		("break_glass" args f1)
                	{tear "piece_medium_steel" bone "doorl1" {impulse up 2 1 dir 2 1}}
		{kill_crew "driver"}
	}
	{on "specability" overload
			{set "specability" 1}
			{call "update_weaponry"}
	}
}
{"iskander"
	{on spawn
		{Volumes "ammo_storage_main" enable contact bullet blast}
		{Volumes "ammo_storage_main1" enable contact bullet blast}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1s"			"basis"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1s"			"FXtraceL4"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1s"			"FXtraceR4"}
		{set "radar_up" 0}
	}
	("9k72_sound")
    {on fire "gun" 
;      		{spawn "dust_shot_big_2" "basis"}
;      		{spawn "dust_shot_big_2" "FXtraceL4"}
;      		{spawn "dust_shot_big_2" "FXtraceR4"}
			{view start "flashbarrel1s"}
			{delay 0.4
				{view pause "flashbarrel1s"}
			}
			
		{if not flag "radar_up"
			{Volumes "ammo_storage_main" disable contact bullet blast}
			{set "radar_up" 1}
      		{spawn "startsmoke_otrk" "missile00"}
		else
			{Volumes "ammo_storage_main1" disable contact bullet blast}
			{set "radar_up" 0}
      		{spawn "startsmoke_otrk" "missile01"}
			{delay 300 
				{Volumes "ammo_storage_main" enable contact bullet blast}
				{Volumes "ammo_storage_main1" enable contact bullet blast}
			}
		}
		
	}
	{on break_armor
		{if volume "cabin" {components "cabin" break} 
		else volume "cabin_back" {components "cabin_back" break} 
		}
	}
	{on pierce
		{if component "ammo_storage_main"
			{spawn "ex_anti_size5" "Gun_rot"}
			{spawn "iskander_ammo" "basis" x {stuff_detonate}}
			{call "_explosion"}
		}
	}
	{on bullet_hit
		(define "check_break_glass"
		     else volume "glass%0"
			{volumes "glass%0" disable bullet contact blast}
	 		{spawn "glass_hit2" "glass%0" x}
	 		{delay 0.1
			 	{bone cut "glass%0"}
	 		}
		)
		{if stuff "radar_ammo"	;чтобы не бить стекла лазерами и радарами
		else stuff "laser_ammo"
		else stuff "rus_IR_ff_beam ammo"
		else stuff "usa_IR_ff_beam ammo"
		else stuff "IR_ff_ammo"
		("check_break_glass" args 1)
		("check_break_glass" args 2)
		("check_break_glass" args 3)
		("check_break_glass" args 4)
		("check_break_glass" args 5)
		("check_break_glass" args 6)
		("check_break_glass" args 7)
		}
	}
	{on break 
		{if component "cabin"  {spawn "tank_die_particle" "cabin"}
		else component "cabin_back" {spawn "tank_die_particle" "Engine"}
		}
	}
	{on repair 
		{if component "cabin"
		else component "cabin_back"
		}
	}
	{on "update_lights"
		{if rain {ani_play "rain" loop} else {ani_stop "rain"}}
	}
	{on "explosion"
		{set "big_explosion" 0}
		{if explosive_amount 400
			{blastwave c4 25 r0 15 r1 35}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
}
{"smerch_common"
	{on spawn
		{add_view 	"startsmoke_big_link" 		"tail00" 		"tail00"}
		{add_view 	"startsmoke_big_link" 		"tail01" 		"tail01"}
		{add_view 	"startsmoke_big_link" 		"tail02" 		"tail02"}
		{add_view 	"startsmoke_big_link" 		"tail03" 		"tail03"}
		{add_view 	"startsmoke_big_link" 		"tail04" 		"tail04"}
		{add_view 	"startsmoke_big_link" 		"tail05" 		"tail05"}
		{add_view 	"startsmoke_big_link" 		"tail06" 		"tail06"}
		{add_view 	"startsmoke_big_link" 		"tail07" 		"tail07"}
		{add_view 	"startsmoke_big_link" 		"tail08" 		"tail08"}
		{add_view 	"startsmoke_big_link" 		"tail09" 		"tail09"}
		{add_view 	"startsmoke_big_link" 		"tail10" 		"tail10"}
		{add_view 	"startsmoke_big_link" 		"tail11" 		"tail11"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel_gun"			"basis"}
		("rand_texmod_1" name1(wood))
	}
	("9k72_sound")
	{on fire "gun" 
;     	{spawn "dust_shot_big_2" "basis"}
		{ani_play "fire"}
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
		}
		(define "fire_barrel"
			name "%0"
				{view start "tail%0"}
				{delay 0.4
					{view pause "tail%0"}
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
			}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 400
			{blastwave c4 25 r0 15 r1 35}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "explosion"
		{set "big_explosion" 0}
		{if explosive_amount 400
			{blastwave c4 25 r0 15 r1 35}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "spawn_shellhole" overload
		{if flag "big_explosion"                                        
			{spawn "crater_extra_big" "basis" terrain_texmod}
                        			{spawn "shellhole_big_dead" "basis"}
		}
	}
	{on "cut_parts"
		 {tear "piece_large_steel" bone "turret" id "turret"
		{impulse dir 0.5 1}
		{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
		else {add_view "smoke_black" "smoke" "basis"}}
		{view start "smoke"}
		{delay_effect 30 5 "pause"}
		 }
	}
}
{"tunguska"
	{on spawn		
		{add_view "autocannon_gilz"	"gun_flash00" "fxshell00"}
		{add_view "autocannon_gilz"	"gun_flash01" "fxshell01"}
		{add_view	 	"flash_gun_big"	"gun_flash00"		"shooter00"}
		{add_view	 	"flash_gun_big"	"gun_flash01"		"shooter01"}
		("rand_texmod_1" name1(camo))
	}
	("shilka_sound")
	("radar_lifting90_params" triplex(additional_triplex) visor(visor3) anim_rotate(radar_loop) anim_lift(radar_lift) marker(antirad_generator_rus))
	{on "init_gun" overload	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{ani_play "fire%0"}
				{view start	"gun_flash%0"}
				{spawn "autocannon_fire" "fxshell%0"   x}
				{spawn "startsmoke_grl" "fxshell%0"   x}
				{spawn "tank_canon_fire_small" "shooter%0"   x}
				{delay 0.2 {view pause	"gun_flash%0"}}
		)
		{if    ("fire_barrel" args 00)
				{spawn "tank_canon_fire_small" "smoke_gunr1"   x}
				{spawn "tank_canon_fire_small" "smoke_gunr2"   x}

			  else ("fire_barrel" args 01)
				{spawn "tank_canon_fire_small" "smoke_gunl1"   x}
				{spawn "tank_canon_fire_small" "smoke_gunl2"   x}

		}
		("cw_check_shooting" weap_id(gun))
	}
	{on ik begin "turret"	;очень мощный привод, когда он работает - корпус качает сильнее, чем от стрельбы.
	       {delay 0.1 "turret_rot"
		{if rand 0.5 {ani_play "hit" 1}
		else	{ani_play "hit" -1}
		}
	       }
	}
	{on ik end "turret"
		{kill_delay "turret_rot"}
	}
	{on "init_gun2"
		{add_view 	"rok_tail"		"tail00"			"tail00"}
		{add_view 	"rok_tail"		"tail01"			"tail01"}
		{add_view 	"rok_tail"		"tail02"			"tail02"}
		{add_view 	"rok_tail"		"tail03"			"tail03"}
		{add_view 	"rok_tail"		"tail04"			"tail04"}
		{add_view 	"rok_tail"		"tail05"			"tail05"}
		{add_view 	"rok_tail"		"tail06"			"tail06"}
		{add_view 	"rok_tail"		"tail07"			"tail07"}
		{add_view 	"startsmoke_link"		"tail03"			"R_shooter03"}
		{add_view 	"startsmoke_link"		"tail04"			"R_shooter04"}
		{add_view 	"startsmoke_link"		"tail05"			"R_shooter05"}
		{add_view 	"startsmoke_link"		"tail06"			"R_shooter06"}
		{add_view 	"startsmoke_link"		"tail07"			"R_shooter07"}
		{add_view 	"startsmoke_link"		"tail00"			"tail00"}
		{add_view 	"startsmoke_link"		"tail01"			"tail01"}
		{add_view 	"startsmoke_link"		"tail02"			"tail02"}
		{add_view 	"startsmoke_link"		"tail03"			"tail03"}
		{add_view 	"startsmoke_link"		"tail04"			"tail04"}
		{add_view 	"startsmoke_link"		"tail05"			"tail05"}
		{add_view 	"startsmoke_link"		"tail06"			"tail06"}
		{add_view 	"startsmoke_link"		"tail07"			"tail07"}
	}
	{on fire "gun2" overload
		(define "fire_barrel"
			name "%0"
				{delay 0.1 
					{if not tagged "radar_off"
						{spawn "9m311_carrier" "R_shooter%0"   x}
					else
			;radar_off indicates shooting without proximity_charge
						{spawn "9m311_carrier" "R_shooter%0"   x
							{delay 1.05 
								{volumes "proximity" disable all}
							}
						}
					}
				}
				{view start "tail%0"}
				{spawn "startsmoke" "R_shooter%0" x}
				{spawn "startsmoke" "tail%0" x}
				{delay 0.4
					{view pause "tail%0"}
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
			}
		("cw_check_shooting" weap_id(gun2))
	}
	{on "cut_parts"
		{if rand 0.5
		     {tear "piece_large_steel" bone "Gun_l1" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Gun_r1" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Radar_Kron"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Radar_r"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
	}
}
{"pantsir"
	{on spawn {tags remove "already_fired"}{call "update_weaponry"}}
	("pantsir_sound")
	("radar_lifting90_double_params" 
		triplex(commander_triplex) visor(visor3) anim_rotate(radar_loop) 
		triplex1(additional_triplex) visor1(visor4) anim_rotate1(none) 
		anim_lift(radar_lift) marker(antirad_generator_rus))
	{on "init_gun" overload	
		{add_view "autocannon_gilz"	"gun_flash00" "fxshell00"}
		{add_view "autocannon_gilz"	"gun_flash01" "fxshell01"}
		{add_view	 	"flash_gun_big"	"gun_flash00"		"shooter00"}
		{add_view	 	"flash_gun_big"	"gun_flash01"		"shooter01"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{ani_play "fire%0"}
				{view start	"gun_flash%0"}
				{spawn "autocannon_fire" "fxshell%0"   x}
				{spawn "startsmoke_grl" "fxshell%0"   x}
				{spawn "tank_canon_fire_small" "shooter%0"   x}
				{delay 0.2 {view pause	"gun_flash%0"}}
		)
		{if    ("fire_barrel" args 00)
				{spawn "tank_canon_fire_small" "smoke_gunr1"   x}
				{spawn "tank_canon_fire_small" "smoke_gunr2"   x}

			  else ("fire_barrel" args 01)
				{spawn "tank_canon_fire_small" "smoke_gunl1"   x}
				{spawn "tank_canon_fire_small" "smoke_gunl2"   x}

		}
		("cw_check_shooting" weap_id(gun))
	}
	{on "cw_panorama_work" overload
		{if not tagged "cw_panorama_work" {ani_play "panorama_custom" callback} } {tags add "cw_panorama_work"}
	}
	{on "cw_panorama_instant_off" overload
		{tags remove "cw_panorama_work"} {ani_stop "panorama_custom"}
	}	
	{on animation_end "panorama_custom"
		{if tagged "cw_panorama_work" {ani_play "panorama_custom" callback}}
	}
	{on "uprise_outriggers"	
	       {if not flag "feather" 
		{ani_play "uprise_outriggers" 1}	
		{set "feather" 1}
	        }
	}
	{on "lower_outriggers"	
	       {if flag "feather" 
		{ani_play "uprise_outriggers" -1}
		{set "feather" 0}
	       }
	}
	{on move on	{kill_delay "outriggers"}			{call "uprise_outriggers"}}
	{on move off	{delay 5 "outriggers"			{call "lower_outriggers"}}}
	{on ik begin "turret" overload
		{kill_delay "rotate_turret"}
		{if not flag "rotate_turret"
			{play_sound "rotate_turret" 1}
			{ani_play "raise_missiles" 1}
			{set "rotate_turret" 1}
		}
	}
	{on ik end "turret" overload
		{delay 5 "rotate_turret"
			{stop_sound "rotate_turret"}
			{ani_play "raise_missiles" -1}
			{set "rotate_turret" 0}
		}
	}
	{on "init_gun2"
		{add_view 	"rok_tail"		"tail00"			"tail00"}
		{add_view 	"rok_tail"		"tail01"			"tail01"}
		{add_view 	"rok_tail"		"tail02"			"tail02"}
		{add_view 	"rok_tail"		"tail03"			"tail03"}
		{add_view 	"rok_tail"		"tail04"			"tail04"}
		{add_view 	"rok_tail"		"tail05"			"tail05"}
		{add_view 	"rok_tail"		"tail06"			"tail06"}
		{add_view 	"rok_tail"		"tail07"			"tail07"}
		{add_view 	"rok_tail"		"tail08"			"tail08"}
		{add_view 	"rok_tail"		"tail09"			"tail09"}
		{add_view 	"rok_tail"		"tail10"			"tail10"}
		{add_view 	"rok_tail"		"tail11"			"tail11"}
		{add_view 	"startsmoke_link"		"tail00"			"R_shooter00"}
		{add_view 	"startsmoke_link"		"tail01"			"R_shooter01"}
		{add_view 	"startsmoke_link"		"tail02"			"R_shooter02"}
		{add_view 	"startsmoke_link"		"tail03"			"R_shooter03"}
		{add_view 	"startsmoke_link"		"tail04"			"R_shooter04"}
		{add_view 	"startsmoke_link"		"tail05"			"R_shooter05"}
		{add_view 	"startsmoke_link"		"tail06"			"R_shooter06"}
		{add_view 	"startsmoke_link"		"tail07"			"R_shooter07"}
		{add_view 	"startsmoke_link"		"tail08"			"R_shooter08"}
		{add_view 	"startsmoke_link"		"tail09"			"R_shooter09"}
		{add_view 	"startsmoke_link"		"tail10"			"R_shooter10"}
		{add_view 	"startsmoke_link"		"tail11"			"R_shooter11"}
		{add_view 	"startsmoke_link"		"tail00"			"tail00"}
		{add_view 	"startsmoke_link"		"tail01"			"tail01"}
		{add_view 	"startsmoke_link"		"tail02"			"tail02"}
		{add_view 	"startsmoke_link"		"tail03"			"tail03"}
		{add_view 	"startsmoke_link"		"tail04"			"tail04"}
		{add_view 	"startsmoke_link"		"tail05"			"tail05"}
		{add_view 	"startsmoke_link"		"tail06"			"tail06"}
		{add_view 	"startsmoke_link"		"tail07"			"tail07"}
		{add_view 	"startsmoke_link"		"tail08"			"tail08"}
		{add_view 	"startsmoke_link"		"tail09"			"tail09"}
		{add_view 	"startsmoke_link"		"tail10"			"tail10"}
		{add_view 	"startsmoke_link"		"tail11"			"tail11"}
	}
	{on fire "gun2" overload
		(define "fire_barrel"
			name "%0"
				{delay 0.5 
					{if not tagged "radar_off"
						{spawn "pantsir_57e6e_carrier" "R_shooter%0"   x}
					else
			;radar_off indicates shooting without proximity_charge
						{spawn "pantsir_57e6e_carrier" "R_shooter%0"   x
							{delay 1.05 
								{volumes "proximity" disable all}
							}
						}
					}
					{view start "tail%0"}
;					{spawn "startsmoke" "R_shooter%0" x}
;					{spawn "startsmoke" "tail%0" x}
					{delay 0.4
						{view pause "tail%0"}
					}
				}				
		)
			{if not flag "rotate_turret"	
				{ani_play "raise_missiles" 1}
				{set "rotate_turret" 1}
			}
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
			}
		("cw_check_shooting" weap_id(gun2))
	 {if  tagged "already_fired"
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}
	  else tagged "radar_off"
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}
	  else not work "radar_off"
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}
	  else 
	  {tags add "already_fired"}
	  {delay 3 {tags remove "already_fired"}}
	 }
	}
	{on "single_launch"
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}

	}
	{on "cut_parts"
		{if rand 0.5
		     {tear "piece_large_steel" bone "Missile_R" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Missile_L" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Radar"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Radar_S"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
	}
}
{"tor_m1"
	{on spawn
		("rand_texmod_0")
	}
	(define "fire_barrel"
		{delay 0.1 
			{delay 0.15 {spawn "tank_canon_fire_small" "tail_0%shooter" x}}
			{delay 0.50 {spawn "tank_canon_fire_small" "tail_0%shooter" x}}
			{delay 0.65
				{bone hide "missilem1_0%shooter"}
				{spawn "9m330_carrier" "shooter_0%shooter"   x {spawn "startsmoke" "medium_tail" x}}
			}
			{delay 0.69
				{ani_play "fire_restore"}
			}
		}
		{bone show "missilem1_0%shooter"}
		{ani_play "fire_frontm1" 0.5}
	)
	{on fire "gun2" 
		{if not flag "feather" {ani_play "open_launcherm1" 10}	{set "feather" 1}}
		{if name "00" ("fire_barrel" shooter(00))
		else name "01" ("fire_barrel" shooter(01))
		else name "02" ("fire_barrel" shooter(02))
		else name "03" ("fire_barrel" shooter(03))
		else name "04" ("fire_barrel" shooter(04))
		else name "05" ("fire_barrel" shooter(05))
		else name "06" ("fire_barrel" shooter(06))
		else name "07" ("fire_barrel" shooter(07))
		}
		{if  tagged "already_fired"
	        {tags remove "already_fired"}
	        {weapon_work "gun2" 0}
	        {delay 6 {call "update_weaponry"}}
	        else tagged "radar_off"
	        {tags remove "already_fired"}
	        {weapon_work "gun2" 0}
	        {delay 6 {call "update_weaponry"}}
	        else not work "radar_off"
	        {tags remove "already_fired"}
	        {weapon_work "gun2" 0}
	        {delay 6 {call "update_weaponry"}}
	        else 
	        {tags add "already_fired"}
	        {delay 3 {tags remove "already_fired"}}
	    }
	}
	{on "single_launch"
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}
	}
	("shilka_sound")
	{on move on	{delay 0.1 {call "update_radar"}{call "update_gun23"}}}
	{on move off	{delay 0.1 {call "update_radar"}{call "update_gun23"}}}
	;{on "update_gun23" overload
	;	{if work "gun2"
	;	      {if work "stabilizer"
	;		    {if work "gunner_panel"
	;		  	  {if not tagged "no_power"
	;				{if not flag "specability"
	;				  {if not velocity 0
	;					  {weapon_work "gun2" 1}
	;				   else {weapon_work "gun2" 0}}
	;				else {weapon_work "gun2" 0}}
	;			  else {weapon_work "gun2" 0}}
	;			else {weapon_work "gun2" 0}}
	;	      else {weapon_work "gun2" 0}}
	;	else {weapon_work "gun2" 0}}
	;}
	("radar_lifting90_params" triplex(commander_triplex) visor(visor1) anim_rotate(radar_loopM1) anim_lift(radar_lift) marker(antirad_generator_rus))
	{on ik begin "turret" {kill_delay "cover"}{if not flag "feather" {ani_play "open_launcherm1"}	{set "feather" 1}}}
	{on ik end "turret" {delay 5 "cover" {if flag "feather" {ani_play "open_launcherm1" -1} {set "feather" 0}}}}
	{on "tear_turret" overload}
}
{"tor_m2"
	{on spawn
		("rand_texmod_0")
	}
	(define "fire_barrel"
		{delay 0.1 
			{delay 0.15 {spawn "tank_canon_fire_small" "tailm2_0%shooter" x}}
			{delay 0.50 {spawn "tank_canon_fire_small" "tailm2_0%shooter" x}}
			{delay 0.65
				{bone hide "missilem2_0%shooter"}
				{spawn "9m338_carrier" "shooterm2_0%shooter"   x {spawn "startsmoke" "medium_tail" x}}
			}
			{delay 0.69
				{ani_play "fire_restore"}
			}
		}
		{bone show "missilem2_0%shooter"}
		{ani_play "fire_frontm2" 0.5}
	)
	{on fire "gun2" 
		{if not flag "feather" {ani_play "open_launcherm2" 10}	{set "feather" 1}}
		{if name "00" ("fire_barrel" shooter(00))
		else name "01" ("fire_barrel" shooter(01))
		else name "02" ("fire_barrel" shooter(02))
		else name "03" ("fire_barrel" shooter(03))
		else name "04" ("fire_barrel" shooter(04))
		else name "05" ("fire_barrel" shooter(05))
		else name "06" ("fire_barrel" shooter(06))
		else name "07" ("fire_barrel" shooter(07))
		else name "08" ("fire_barrel" shooter(08))
		else name "09" ("fire_barrel" shooter(09))
		else name "10" ("fire_barrel" shooter(10))
		else name "11" ("fire_barrel" shooter(11))
		else name "12" ("fire_barrel" shooter(12))
		else name "13" ("fire_barrel" shooter(13))
		else name "14" ("fire_barrel" shooter(14))
		else name "15" ("fire_barrel" shooter(15))
		}
		{if  tagged "already_fired"
	        {tags remove "already_fired"}
	        {weapon_work "gun2" 0}
	        {delay 6 {call "update_weaponry"}}
	        else tagged "radar_off"
	        {tags remove "already_fired"}
	        {weapon_work "gun2" 0}
	        {delay 6 {call "update_weaponry"}}
	        else not work "radar_off"
	        {tags remove "already_fired"}
	        {weapon_work "gun2" 0}
	        {delay 6 {call "update_weaponry"}}
	        else 
	        {tags add "already_fired"}
	        {delay 3 {tags remove "already_fired"}}
	    }
	}
	{on "single_launch"
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}
	}
	("shilka_sound")
	("radar_lifting90_params" triplex(commander_triplex) visor(visor1) anim_rotate(radar_loopM2) anim_lift(radar_lift) marker(antirad_generator_rus))
	{on ik begin "turret" {kill_delay "cover"}{if not flag "feather" {ani_play "open_launcherm2"}	{set "feather" 1}}}
	{on ik end "turret" {delay 5 "cover" {if flag "feather" {ani_play "open_launcherm2" -1} {set "feather" 0}}}}
	{on "tear_turret" overload}
}

{"buk_launcher"
	{on spawn
		("rand_texmod_1" name1(camo))
	}
	("shilka_sound")
	{on move on	{delay 0.1 {call "update_radar"}{call "update_gun23"}}}
	{on move off	{delay 0.1 {call "update_radar"}{call "update_gun23"}}}
	{on "update_gun23" overload
		{if work "gun2"
		      {if work "stabilizer"
			    {if work "gunner_panel"
			  	  {if not tagged "no_power"
					{if not flag "specability"
					  {if not velocity 0
						  {weapon_work "gun2" 1}
					   else {weapon_work "gun2" 0}}
					else {weapon_work "gun2" 0}}
				  else {weapon_work "gun2" 0}}
				else {weapon_work "gun2" 0}}
		      else {weapon_work "gun2" 0}}
		else {weapon_work "gun2" 0}}
	}
	{on "update_radar"
		{if tagged "radar_off" {weapon_work "radar" 0}
		else not work "commander_triplex" {weapon_work "radar" 0}
		else not work "body" {weapon_work "radar" 0}
		else not work "turret" {weapon_work "radar" 0}
		else not work "radar" {weapon_work "radar" 0}
		else tagged "no_power" {weapon_work "radar" 0}
		else velocity 0 {weapon_work "radar" 0}
		else {weapon_work "radar" 1}
		}
	}
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight1) tail(tail) shooter(shooter))
	;("custom_multi_launcher" weapon(gun2) tail(tail) shooter(shooter) missile(9m38))
	("radar_params" triplex(commander_triplex) visor(visor1) anim_rotate(none) marker(antirad_generator_large_rus))
}
{"9s18_kupol"
	{on spawn
		("rand_texmod_1" name1(wood))
	}
	("shilka_sound")
	{on "update_radar"
		{if tagged "radar_off" {weapon_work "radar" 0}
		else not work "commander_triplex" {weapon_work "radar" 0}
		else not work "body" {weapon_work "radar" 0}
		else not work "turret" {weapon_work "radar" 0}
		else not work "radar" {weapon_work "radar" 0}
		else tagged "no_power" {weapon_work "radar" 0}
		else {weapon_work "radar" 1}
		}
	}
	{on crew out
		{if crew_in_place "driver" {tags add "kupol_moves"}{call "update_antiradar"}}
	}
	{on crew in
		{if crew_in_place "commander" {delay 20 {call "update_antiradar"}}}
	}
	{on break
		{if component "commander_triplex" {call "update_antiradar"}}
	}
	{on repair
		{if component "commander_triplex" {call "update_antiradar"}}
	}
	{on "update_antiradar" overload
			{if crew_in_place "commander"
			  {if not tagged "no_power"
			   {if not tagged "cwsh_passive"
				 {if work "commander_triplex"
				   {if tagged "kupol_moves"
					{call "cwsh_radar_on"}
				   else not tagged "radar_off"
				    {call "cwsh_radar_on"}
				   else 
				    {call "cwsh_radar_off"}
				   }
				 else
					{call "cwsh_radar_off"}
				}
			   else
				{call "cwsh_radar_off"}
			   }
			  else
				{call "cwsh_radar_off"}
			  }
			else
				{call "cwsh_radar_off"}
			}
	}
	
	{on animation_end "radar_loop"
		{if not tagged "kupol_moves"
			{if not flag "specability"
				{ani_play "radar_loop_front" callback}
			  else
				{ani_play "radar_loop" callback}
			}
		}
	}
	{on animation_end "radar_loop_front"
		{if not tagged "kupol_moves"
			{if not flag "specability"
				{ani_play "radar_loop_front" callback}
			  else
				{ani_play "radar_loop" callback}
			}
		}
	}
	{on "specability" overload
		{if not flag "specability"
			{set "specability" 1}
		else 
			{set "specability" 0}
		}
	}
	{on ik begin "turret" overload
		{kill_delay "rotate_turret"}
		{ani_play "radar_loop"}
		{ani_stop "radar_loop"}
		{ani_stop "radar_loop_front"}
		{set "radar_up" 0}
	}
	{on ik end "turret"
		{delay 5 "rotate_turret"
			{call "update_antiradar"}
		}
	}
	{on fire "radar"
		{kill_delay "rotate_turret"}
		{ani_stop "radar_loop"}
		{ani_stop "radar_loop_front"}
		{set "radar_up" 0}
		{delay 5 "rotate_turret"
			{call "update_antiradar"}
		}
	}
	{on "cwsh_radar_on"
		{tags remove "kupol_moves"}
		{if work "commander_triplex"
		 {if not flag "radar_up"
		  {if not flag "specability"
			{ani_play "radar_loop_front" callback}
		  else
			{ani_play "radar_loop" callback}
		  }
		  {set "radar_up" 1}
		 }
		  {delay 0.1 {ani_play "visor1" -1}}
			{with_linked_entity "vehicle9"
				{call "start"}
			}
		}
	}
	{on "cwsh_radar_off"
		{ani_stop "radar_loop"}
		{ani_stop "radar_loop_front"}
		{set "radar_up" 0}
		{delay 0.1 {ani_play "visor1"}}
		{with_linked_entity "vehicle9"
			{call "stop"}
		}
	}
}
{"sprutsd"
	{on spawn
		("rand_texmod_1" name1(wood))
	}
	("bmd4m_sound")
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "poddon_cannon" "turret_systems" x 
			{impulse up 1 0.7 dir 2.5 0.7 cz 0.2 0.1 forward -5 1 com}
		}
	}
    	{on "init_gun"
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
	}
	("110-130mm_gun_with_cm")
	;gun can be disabled by specability
	{on "update_gun"
		{if work "gun"
			 {if work "stabilizer"
			  {if work "gunner_panel"
				{if not flag "specability"
				  {if not tagged "contusion"
					{if not tagged "cw_autoloader_stuck"
						{weapon_work "gun" 1}
					else {weapon_work "gun" 0}}
				  else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			  else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
	{on "emit_desant"
		{delay 0.1 {with_linked_entity "seat1"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
		{delay 0.1 {with_linked_entity "seat2"	{throw_off up 0.3 0.1 dir 5.5 2 forward 2 turn 0 360 force}}}
	}
}
{"btr-d"
	("btr-d")
}
{"btr-d_zu"
	("btr-d")
}
{"btr-rd"
	("btr-d")
}
{"b_tr80_kliver"
	{on spawn
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
  	}
	("btr80_sound")
	("Kliver_module")
}
{"bmp1_kliver"
	("bmp1_sound")
	("Kliver_module")
}
{"bmpt"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}			
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}	
		{add_view 	"smoke_zenit" 	"zenite_smoke1" 		"foresight2"}
		{add_view	 "flash_gun_big"	"flashbarrel7"	"Foresight7"}
		{add_view "zenit_gilz"		"shells_we"	"fxshell"}

		{add_view 	"smoke_zenit" 	"smoke_L00" 		"taill_00"}
		{add_view 	"rok_tail"	                            "tail_L00"			"taill_00"}
		{add_view 	"smoke_zenit" 	"smoke_L01" 		"taill_01"}
		{add_view 	"rok_tail"	                            "tail_L01"			"taill_01"}
		{add_view 	"smoke_zenit" 	"smoke_R00" 		"tailr_00"}
		{add_view 	"rok_tail"	                            "tail_R00"			"tailr_00"}
		{add_view 	"smoke_zenit" 	"smoke_R01" 		"tailr_01"}
		{add_view 	"rok_tail"	                            "tail_R01"			"tailr_01"}

		{add_view	 	"BMP2_canon_fire"	"flashbarrel1"		"Foresight1"}
		{add_view	 	"BMP2_canon_fire"	"flashbarrel2"		"Foresight2"}
		{add_view	"autocannon_fire_link"		"flashbarrel1"			"Foresight1"}
		{add_view	"autocannon_fire_link"		"flashbarrel2"			"Foresight2"}
    	}
	("t90_sound")
;	("atgm_multi_launcher" weapon(gun2) foresight(foresight4) tail(tailR_))
;	("atgm_multi_launcher" weapon(gun3) foresight(foresight3) tail(tailL_))
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight4) tail(taill_) shooter(shooterl_))
	("custom_sh_multi_launcher" weapon(gun3) foresight(foresight3) tail(tailr_) shooter(shooterr_))
    {on fire "gun" overload
;		{spawn "autocannon_fire" "Foresight1" x}
		{view start "flashbarrel1"}
		{delay 0.42 {view pause "flashbarrel1"}}
		{ani_play "fire"}
		{delay 0.12 
			{start_sound "weapon/shot/shell"}
			{spawn "gilza_20mm" "fxshell00" x scale 1.5
				{impulse up 0.01 0.01 dir 0.0 0.0 cz 1.2 1.1 forward 2 0.5 com}
			}
		}
		("cw_check_shooting" weap_id(gun))
	}
    {on fire "gun1" overload
;		{spawn "autocannon_fire" "Foresight2" x}
		{view start "flashbarrel2"}
		{delay 0.42 {view pause "flashbarrel2"}}
		{ani_play "fire1"}
		{delay 0.12 
			{start_sound "weapon/shot/shell"}
			{spawn "gilza_20mm" "fxshell01" x scale 1.5
				{impulse up 0.01 0.01 dir 0.0 0.0 cz 1.2 1.1 forward 2 0.5 com}
			}
		}
		("cw_check_shooting" weap_id(gun1))
	}
	{on fire "mgun" overload
		{view start "flashbarrel7"}
		{view show	"shells_we"}
		{view start	"shells_we"}
		{delay 0.2	{view pause	"shells_we"}}
		("cw_check_shooting" weap_id(mgun))
	}
	{on fire "mgun1" overload
;		{spawn "startsmoke" inv_normal}
		("cw_check_shooting" weap_id(mgun1))
	}
	{on fire "mgun2" overload
;		{spawn "startsmoke" inv_normal}
		("cw_check_shooting" weap_id(mgun2))
	}
;	("shtora_smoke_mortar" mgun_id(20))
;	("shtora_smoke_mortar" mgun_id(21))
	{on break overload
		{if 	component "fuel_tank_internal_a"
		     {if not tagged "destroyed"
		       {damage_report "fuel_tank_external_a" "fuel:fuel_tank_damaged"}
		      {if rand 0.2
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8 {spawn "ex_air_big"}}
			{delay 1		{crew_emit}}
			{delay 2		{crew_emit}}
			{delay 3		{crew_emit}}
		      }
		}
	else component "fuel_tank_internal_b"
		{if not tagged "destroyed"
			{damage_report "fuel_tank_external_b" "fuel:fuel_tank_damaged"}
		      {if rand 0.2
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8 {spawn "ex_air_big"}}
			{delay 1		{crew_emit}}
			{delay 2		{crew_emit}}
			{delay 3		{crew_emit}}
		      }
		}
	else component "fuel_tank_internal_c"
		{if not tagged "destroyed"
			{damage_report "fuel_tank_external_c" "fuel:fuel_tank_damaged"}
		      {if rand 0.2
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8 {spawn "ex_air_big"}}
			{delay 1		{crew_emit}}
			{delay 2		{crew_emit}}
			{delay 3		{crew_emit}}
		      }
		}
	else component "fuel_tank_internal_d"
		{if not tagged "destroyed"
			{damage_report "fuel_tank_external_d" "fuel:fuel_tank_damaged"}
		      {if rand 0.2
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8 {spawn "ex_air_big"}}
			{delay 1		{crew_emit}}
			{delay 2		{crew_emit}}
			{delay 3		{crew_emit}}
		      }
		}
		else {inherited}
		}
	}
}
{"tos-1a_solntsepek"
	{on spawn
		{add_view 	"startsmoke_big_link" 		"rok_tail00" 		"tail_00"}
		{add_view 	"startsmoke_big_link" 		"rok_tail01" 		"tail_01"}
		{add_view 	"startsmoke_big_link" 		"rok_tail02" 		"tail_02"}
		{add_view 	"startsmoke_big_link" 		"rok_tail03" 		"tail_03"}
		{add_view 	"startsmoke_big_link" 		"rok_tail04" 		"tail_04"}
		{add_view 	"startsmoke_big_link" 		"rok_tail05" 		"tail_05"}
		{add_view 	"startsmoke_big_link" 		"rok_tail06" 		"tail_06"}
		{add_view 	"startsmoke_big_link" 		"rok_tail07" 		"tail_07"}
		{add_view 	"startsmoke_big_link" 		"rok_tail08" 		"tail_08"}
		{add_view 	"startsmoke_big_link" 		"rok_tail09" 		"tail_09"}
		{add_view 	"startsmoke_big_link" 		"rok_tail10" 		"tail_10"}
		{add_view 	"startsmoke_big_link" 		"rok_tail11" 		"tail_11"}
		{add_view 	"startsmoke_big_link" 		"rok_tail12" 		"tail_12"}
		{add_view 	"startsmoke_big_link" 		"rok_tail13" 		"tail_13"}
		{add_view 	"startsmoke_big_link" 		"rok_tail14" 		"tail_14"}
		{add_view 	"startsmoke_big_link" 		"rok_tail15" 		"tail_15"}
		{add_view 	"startsmoke_big_link" 		"rok_tail16" 		"tail_16"}
		{add_view 	"startsmoke_big_link" 		"rok_tail17" 		"tail_17"}
		{add_view 	"startsmoke_big_link" 		"rok_tail18" 		"tail_18"}
		{add_view 	"startsmoke_big_link" 		"rok_tail19" 		"tail_19"}
		{add_view 	"startsmoke_big_link" 		"rok_tail20" 		"tail_20"}
		{add_view 	"startsmoke_big_link" 		"rok_tail21" 		"tail_21"}
		{add_view 	"startsmoke_big_link" 		"rok_tail22" 		"tail_22"}
		{add_view 	"startsmoke_big_link" 		"rok_tail23" 		"tail_23"}
		("rand_texmod_0")
	}
	("t90_sound")
	{on fire "gun" 
			(define "fire_barrel"
			name "%0"
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
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
			}
;		{spawn "startsmoke_big" inv_normal}
;		 {if rand 0.5
;      			{spawn "dust_shot_big_2" "basis"}
;		}
		{ani_play "fire"}
		("cw_check_shooting" weap_id(gun))
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 400
			{blastwave c4 25 r0 15 r1 35}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "explosion"
		{set "big_explosion" 0}
		{if explosive_amount 400
			{blastwave c4 25 r0 15 r1 35}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "spawn_shellhole"
		{if flag "big_explosion"                                        
			{spawn "crater_extra_big" "basis" terrain_texmod}
                        			{spawn "shellhole_big_dead" "basis"}
		}
	}
	("smokegun_nospread" smokegun(mgun20))
	("smokegun_nospread" smokegun(mgun21))

}

{"t90sm_test"
	{on "kill_crew" overload
	    {kill_crew "gunner"}
        {kill_crew "charger"}
        {kill_crew "commander"}
        {kill_crew "driver"}
	}
}

{"krasnopol_user"
    {on contact 
		{if effector "krasnopol_spawner"
			{if not tagged "krasnopol_spawned"
				{tags add "krasnopol_spawned"}
				{spawn "krasnopol_test" "Foresight1" x}
				{delay 1.0 {tags remove "krasnopol_spawned"}}
			}
		}
	}
}
;=======================================
;----------------------------------Pheonix game(c) 2012---------------
