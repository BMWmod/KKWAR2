;-------------------------------------------=======================Defines=============================
;=======================mow2=============================
(define "pz2_sound")
(define "pz3_spg_sound")
(define "m3a1_sound")
;=======================CW=============================
(define "t34_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/t34/t34_tracks"}
		{link_sound "engine"			"vehicle/groundborne/t34/t34_engine"}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00"}
		{link_sound "exhaust"			"vehicle/groundborne/t34/t34_exhaust"}
		{link_sound "rotate_turret" 	"vehicle/groundborne/t34/t34_turret"}
	}
)
(define "t62_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t72_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/t62md_engine"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t55_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/t62md_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/t62md_engine_off"}
	}
)
(define "t62m_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t62md_loaded_rpm"}
		{link_sound "engine"		"vehicle/engine_cw/t62md_engine"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t55_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/t62md_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/t62md_engine_off"}
	}
)
(define "t64_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t55_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/t64_engine"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/turret-2"}
		{link_sound "exhaust"		"vehicle/engine_cw/t64_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/t64_engine_off"}
	}
)
(define "t72_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t72_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/t72_engine"	}
		{link_sound "engine_end"		"vehicle/engine_cw/t-72-engineoff"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t-72-turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/t-72-enginestart"}
	}
)
(define "t80_sound"
	{on "add_movement_sound" overload		;как и у абрамса, гтд
		{link_sound "move"			"vehicle/tracks_cw/t72_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/t80u_engine"}
		{link_sound "engine_end"		"vehicle/engine_cw/t80u_engine_off"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t-72-turret"}
		{link_sound "exhaust"		"vehicle/abrams/m1_engineon"}
	}
)
(define "t90_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t72_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/t-90working"}
		{link_sound "engine_end"		"vehicle/engine_cw/t-90off"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t-90turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/t-90start"}
	}
)
(define "t14_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t72_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/t14working"}
		{link_sound "engine_end"		"vehicle/engine_cw/t-90off"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t-90turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/t14start"}
	}
)
(define "msta_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t72_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/msta_engine"}
		{link_sound "engine_end"		"vehicle/engine_cw/msta-engine_off"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t-72-turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/msta-engine_start"}
	}
)
(define "mtlb_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t55_tracks"}
		{link_sound "engine"			"vehicle/engine_cw/mtlb_work"		}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"			"vehicle/engine_cw/mtlb_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/mtlb_stop"	}
	}
)
(define "uran9_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/wiesel_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/engine_bmd"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/2_light"}
		{link_sound "exhaust"		"vehicle/engine_cw/bmp_up"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmp_end"}
	}
)
(define "bmp1_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/bmp2_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/bmp_rus_engine"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"		"vehicle/engine_cw/bmp_rus_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmp_end"}
	}
)
(define "bmp3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t55_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/bmp3_engine"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m2"}
		{link_sound "exhaust"		"vehicle/engine_cw/bmp3_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmp3_stop"}
	}
)
(define "bmd_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/bmp2_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/engine_bmd"	}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"	}
		{link_sound "exhaust"		"vehicle/engine_cw/bmp_up"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmp_end"}
	}
)
(define "bmd4m_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/bmd_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/bmd4m_work"	}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m2"	}
		{link_sound "exhaust"		"vehicle/engine_cw/bmd4m_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmd4m_stop"}
	}
)
(define "brdm_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/truck_loop_3"}
		{link_sound "engine"		"vehicle/engine_cw/gaz66_work"	}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"	}
		{link_sound "exhaust"		"vehicle/engine_cw/gaz66_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/gaz66_stop"}
	}
)
(define "btr60_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/truck_loop_3"}
		{link_sound "engine"		"vehicle/engine_cw/btr60_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"		"vehicle/engine_cw/btr60_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/btr60_stop"}
	}
)
(define "btr80_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/truck_loop_3"}
		{link_sound "engine"		"vehicle/engine_cw/engine_btr70"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"		"vehicle/engine_cw/shilka_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/brdm_shut_off"}
	}
)
(define "btr90_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/truck_loop_3"}
		{link_sound "engine"		"vehicle/engine_cw/bmp_rus_engine"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"		"vehicle/engine_cw/bmp_rus_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmp_end"}
	}
)
(define "bumerang_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/truck_loop_3"}
		{link_sound "engine"		"vehicle/engine_cw/bumerang_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"		"vehicle/engine_cw/bumerang_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmp_end"}
	}
)
(define "kurganec_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/t55_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/bumerang_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"		"vehicle/engine_cw/bumerang_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bmp_end"}
	}
)
(define "shilka_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/shilka_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/shilka_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m2"}
		{link_sound "exhaust"		"vehicle/engine_cw/shilka_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/shilka_shut_off"}
	}
)
(define "pantsir_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/kamaz_loop"		}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/pantsir_turret"}
		{link_sound "engine_end"		"vehicle/engine_cw/kamaz_shut_off"	}
		{link_sound "exhaust"			"vehicle/engine_cw/kamaz_start"}
	}
)
(define "9k72_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/btr_70_loop"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "engine"			"vehicle/engine_cw/maz_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/maz_stop"	}
		{link_sound "exhaust"			"vehicle/engine_cw/maz_start"}
	}
)
(define "warrior_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/fv432_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/warrior_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
		{link_sound "exhaust"		"vehicle/engine_cw/warrior_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/warrior_stop"}
	}
)
(define "fv432_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/fv432_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/fv432_work"}
		{link_sound "exhaust"		"vehicle/engine_cw/fv432_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/fv432_stop"}
	}
)
(define "fv107_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/fv432_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/fv107_work"}
		{link_sound "exhaust"		"vehicle/engine_cw/fv107_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/fv107_stop"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m1"}
	}
)
(define "ajax_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/ajax_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/ajax_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/ajax_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/ajax_stop"}
	}
)
(define "bredly_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/m113_track"}
		{link_sound "engine"		"vehicle/engine_cw/bredly_working"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/bredly_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bredly_off"}
	}
)
(define "m270_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/m113_track"}
		{link_sound "engine"		"vehicle/engine_cw/bredly_working"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m270_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/bredly_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/bredly_off"}
	}
)
(define "paladin_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/1_abrams_move"}
		{link_sound "engine"		"vehicle/engine_cw/paladin_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/paladin_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/paladin_stop"}
	}
)
(define "wiesel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/wiesel_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/wiesel_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/wiesel_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/wiesel_stop"}
	}
)
(define "aavp7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/1_abrams_move"}
		{link_sound "engine"		"vehicle/engine_cw/aavp_working"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/aavp_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/aavp_off"}
	}
)
(define "m60_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/1_abrams_move"}
		{link_sound "engine"		"vehicle/engine_cw/m60_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/m60_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/m60_end"}
	}
)
(define "abrams_sound"
	{on "add_movement_sound" overload
		{link_sound "move"	     		"vehicle/tracks_cw/m1a1_tracks"}							
		{link_sound "engine"		"vehicle/engine_cw/abrams_engine"}
		{link_sound "engine_end"		"vehicle/engine_cw/abrams_off"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust" 		"vehicle/engine_cw/abrams_start"	}
	}
)
(define "zulfiqar_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/1_abrams_move"}
		{link_sound "engine"		"vehicle/engine_cw/t72_engine"	}
		{link_sound "engine_end"		"vehicle/engine_cw/t-72-engineoff"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t-72-turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/t-72-enginestart"}
	}
)
(define "marder_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/puma_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/marder_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/marder_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/marder_stop"}
	}
)
(define "puma_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/puma_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/puma_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/puma_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/puma_stop"}
	}
)
(define "boxer_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/boxer_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/boxer_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/boxer_stop"}
	}
)
(define "vbci_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/vbci_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/vbci_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/vbci_stop"}
	}
)
(define "patria_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/patria_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/atria_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/atria_stop"}
	}
)
(define "vbl_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/truck_loop_3"}
		{link_sound "engine"		"vehicle/engine_cw/vbl_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light1"}
		{link_sound "exhaust"		"vehicle/engine_cw/vbl_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/vbl_stop"}
	}
)
(define "fennek_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/truck_loop_3"}
		{link_sound "engine"		"vehicle/engine_cw/fennek_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light1"}
		{link_sound "exhaust"		"vehicle/engine_cw/fennek_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/fennek_stop"}
	}
)
(define "vab_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/vab_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/vab_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/vab_stop"}
	}
)
(define "amx10rc_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/amx10rc_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/amx10rc_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/amx10rc_stop"}
	}
)
(define "leopard_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/leopard2_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/leopard1_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/leopard2_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/leopard1_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/leopard1_stop"}
	}
)
(define "leopard2_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/leopard2_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/leo2_engine_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m2"}
		{link_sound "exhaust"		"vehicle/engine_cw/leo2_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/challenger2_engine_stop"}
	}
)
(define "caesar_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/caesar_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/caesar_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/caesar_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/caesar_stop"}
	}
)
(define "challenger_2_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/tracks_chellanger2"}
		{link_sound "engine"		"vehicle/engine_cw/challenger2_engine_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/challanger2_traverse"}
		{link_sound "exhaust"		"vehicle/engine_cw/challenger2_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/challenger2_engine_stop"}
	}
)
(define "leclerc_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/leclerc_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/leclerc_engine_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/light_m2"}
		{link_sound "exhaust"		"vehicle/engine_cw/leclerc_engine_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/leclerc_engine_off"}
	}
)
(define "merkava4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/merkava_track"}
		{link_sound "engine"		"vehicle/engine_cw/leo2_engine_work"}
		{link_sound "engine_end"		"vehicle/engine_cw/challenger2_engine_stop"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/t-72-turret"}
		{link_sound "exhaust"		"vehicle/abrams/leo2_engine_start"}
	}
)
(define "lav25_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/lav_working"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/traverse_nato"}
		{link_sound "exhaust"		"vehicle/engine_cw/lav_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/lav_off"}
	}
)
(define "stryker_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/stryker_loop"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/stryker_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/stryker_off"}
	}
)
(define "dana_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/dana_engine"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"	}
		{link_sound "exhaust"		"vehicle/engine_cw/dana_enginge_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/msta-engine_off"}
	}
)
(define "m113_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/m113_track"}
		{link_sound "engine"		"vehicle/engine_cw/m113_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/m113_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/m113_end"}
	}
)
(define "tpz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/tpz_fuchs_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/m1a1_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/tpz_fuchs_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/tpz_fuchs_stop"}
	}
)
(define "zsl92_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels_cw/4wd_loop"}
		{link_sound "engine"		"vehicle/engine_cw/zsl_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/china_turret_engine_move"}
		{link_sound "exhaust"		"vehicle/engine_cw/zsl_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/zsl_stop"}
	}
)
(define "zbd04_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/zbd04a_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/zbd04a_work"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/china_turret_engine_move"}
		{link_sound "exhaust"		"vehicle/engine_cw/bmp3_start"}
		{link_sound "engine_end"		"vehicle/engine_cw/zbd04a_stop"}
	}
)
(define "ztz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks_cw/ztz99_tracks"}
		{link_sound "engine"		"vehicle/engine_cw/ztz_work"	}
		{link_sound "engine_end"		"vehicle/engine_cw/ztz_stop"}
		{link_sound "rotate_turret" 		"vehicle/turret_cw/ztz_turret"}
		{link_sound "exhaust"		"vehicle/engine_cw/ztz_start"}
	}
)
(define "ee9_cascavel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/4wd_Loop"}
		{link_sound "engine"		"vehicle/engine/cascavel_work"}
		{link_sound "rotate_turret" 		"vehicle/turret/light1"}
		{link_sound "exhaust"		"vehicle/engine/cascavel_start"}
		{link_sound "engine_end"		"vehicle/engine/cascavel_stop"}
	}
)
;=======================Gun=============================
(define "custom_gilza"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "%type" "%bone" x scale %scale
			{impulse up %up 0.5 dir 2.5 0.7 cz 0.2 0.1 forward %forward 0.5 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 6 2 "stop"}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "25-50mm_gilza"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "gilza_20mm" "%fxshell" x scale 1.5
			{impulse up 0.01 0.01 dir 0.0 0.0 cz 1.2 1.1 forward 2 0.5 com}
		}
	}
)
(define "2a46_poddon"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "poddon_cannon" "turret_systems" x scale 1
			{impulse up 3 0.7 dir 3 0.7 cz 0.2 0.1 forward -2.5 0.5 com}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "90-105mm_gilza"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "turret_systems" x scale 1.0
			{impulse up 2.5 0.7 dir 2.5 0.7 cz 0.2 0.1 forward -2 0.5 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 6 2 "stop"}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "90-105mm_gilza_bone"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "%bone" x scale 1.0
			{impulse up 2.5 0.7 dir 2.5 0.7 cz 0.2 0.1 forward -2 0.5 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 6 2 "stop"}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "90-105mm_gilza_back"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "turret_systems" x scale 1.0
			{impulse up 0.1 0.1 forward 2 0.5 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 6 2 "stop"}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "110-130mm_gilza"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "turret_systems" x scale 1.1
			{impulse up 2.5 0.7 dir 2.5 0.7 cz 0.2 0.1 forward -2 0.5 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 6 2 "stop"}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "135-180mm_gilza"
	{on "spawn_shell" 
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "turret_systems" x scale 1.5
			{impulse up 0.2 0.1 dir 2.5 0.7 cz 0.2 0.1 forward -2 0.5 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 6 2 "stop"}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "135-180mm_gilza_forward"
	{on "spawn_shell" 
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "turret_systems" x scale 1.5
			{impulse up 0.2 0.1 dir 2.5 0.7 cz 0.2 0.1 forward 2 0.5 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 6 2 "stop"}
			{delay 6 2.5 {hide 3}}
		}
	}
)
(define "no_gilza_ejection"
	{on "spawn_shell" overload}
)
(define "tank_gun"
	{view start "flashbarrel_gun"}
	{view start "smoke_add"}
	{delay 0.16 "shell_off"
		{view start "zenite_smoke"}
		{view pause "smoke_add"}
		{view pause "flashbarrel_gun"}
		{delay 1	{call "spawn_shell"}}
		{delay 2	{view pause "zenite_smoke"}}
	}
)
(define "autocannon"
	{on "init1_gun"
		{add_view	"tank_canon_fire_small_link"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun" overload
;		{spawn "tank_canon_fire_small" "Foresight1" x}
		{view start "flashbarrel1"}
		{delay 0.42
			{view pause "flashbarrel1"}
		}
		{ani_play "fire"}
		{delay 0.05 {call "spawn_shell"}}
		("cw_check_shooting" weap_id(gun))
	}
;	{on "init_gun" overload}	;чтобы не было факела из пушки при выгорании
)
(define "autocannon_muzzle_brake"
	{on "init1_gun"
		{add_view	"autocannon_fire_muzzle_brake_link"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun" overload
;		{spawn "autocannon_fire_muzzle_brake" "Foresight1" x}
		{view start "flashbarrel1"}
		{delay 0.42
			{view pause "flashbarrel1"}
		}
		{ani_play "fire"}
		{delay 0.2 {call "spawn_shell"}}
		("cw_check_shooting" weap_id(gun))
	}
)
(define "90-105mm_gun_with_cm"
	{on "init_burnout"
	      {if rand 0.3
			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
	       }
	}
	{on "init1_gun"
		{add_view	"tank_canon_fire_3_link"		"flashbarrel1"			"Foresight1"}
	}
   {on fire "gun" 
		("tank_gun")
		{set "gun"}{call "proj_probe"}
		{spawn "dust_shot_normal" "basis"}
;    	{spawn "tank_canon_fire_3" "Foresight1" x}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
	}
)
(define "110-130mm_gun_with_cm"
	{on "init_burnout"
	      {if rand 0.3
			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
	       }
	}
 	{on "init1_gun"
		{add_view	"tank_canon_fire_3_link"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun" 
		("tank_gun")
		{set "gun"}{call "proj_probe"}
		{spawn "dust_shot_big" "basis"}
;		{spawn "tank_canon_fire_3" "Foresight1" x}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
	}
)
(define "135-180mm_sph_gun"
	{on "init_burnout"
	      {if rand 0.3
			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
	       }
	}
 	{on "init1_gun"
		{add_view	"canon_gaub_fire_link"		"flashbarrel1"			"Foresight1"}
		{add_view	"dust_shot_big_link"		"flashbarrel1"			"basis"}
	}
    {on fire "gun" 
		("tank_gun")
;		{spawn "dust_shot_big" "basis"}
;		{spawn "canon_gaub_fire" "Foresight1" x}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
	}
)
(define "14_7mm_kpvt"
	{on fire "gun" overload
		{view start "flashbarrel1"}
		{delay 0.42
			{view pause "flashbarrel1"}
		}
		{ani_play "fire"}
		("cw_check_shooting" weap_id(gun))
	}
	{on "update_gun"
		{if work "gun"
			 {if work "stabilizer"
			   {if work "gunner_panel"
				{if not flag "specability"
				  {if not tagged "contusion"
					{weapon_work "gun" 1}
				  else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			   else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
)
(define "small_multibarrel_gun"
	{on "init_gun"
		{add_view "flash_zenit"	"flashbarrel00"	"%shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"%shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"%shooter02"}
		{add_view "flash_zenit"	"flashbarrel03"	"%shooter03"}
		{add_view "autocannon_gilz"	"gilz00" "%fxshell00"}
		{add_view "autocannon_gilz"	"gilz01" "%fxshell01"}
		{add_view "autocannon_gilz"	"gilz02" "%fxshell02"}
		{add_view "autocannon_gilz"	"gilz03" "%fxshell03"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42 {view pause "flashbarrel%0"}}
				{ani_play "fire%0"}
				{view start	"gilz%0"}
				{view show	"gilz%0"}
				{delay 0.2 {view pause	"gilz%0"}}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
		("cw_check_shooting" weap_id(gun))
	}
)
(define "gatling_gun"
 	{on "init1_gun"
		{add_view       "zenit_gilz"	"shell"	        "%FXshell"}	
		{add_view	"autocannon_fire_link"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun" overload
;		{spawn "autocannon_fire" "Foresight1" x}
		{view start "flashbarrel1"}
		{view start "shell"}
		{kill_delay "shell"}
		{delay 0.42 "shell"
			{view pause "flashbarrel1"}
			{view pause "shell"}
			{set "die_sound" 0}
		}
		{if not flag "die_sound" {ani_play "fire" callback}}
		{set "die_sound" 1}
		("cw_check_shooting" weap_id(gun))
	}
	{on animation_end "fire"
		{if flag "die_sound" {ani_play "fire" callback}}
	}
)
(define "25mm_bushmaster"
    	("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
)
(define "30mm_2a42"
	("autocannon_muzzle_brake")
	("25-50mm_gilza" fxshell(fxshell_canon))
)
(define "30mm_2a72"
	("autocannon")
	("25-50mm_gilza" fxshell(fxshell_canon))
)
(define "30mm_2a42_gun1"
 	{on "init_gun"
		{add_view	"autocannon_fire_muzzle_brake_link"		"flashbarrel2"			"Foresight6"}
	}
	{on fire "gun1" overload
;		{spawn "autocannon_fire_muzzle_brake" "Foresight6" x}
		{view start "flashbarrel2"}
		{delay 0.42
			{view pause "flashbarrel2"}
		}
		{ani_play "fire2"}
		{delay 0.1 {call "spawn_shell1"}}
		("cw_check_shooting" weap_id(gun1))
	}
	{on "spawn_shell1"
		{start_sound "weapon/shot/shell"}
		{spawn "gilza_20mm" "fxshell_canon" x scale 1.5
			{impulse up 0.01 0.01 dir 0.0 0.0 cz 1.2 1.1 forward 2 0.5 com}
		}
	}
)
(define "73mm_2a28_grom"
	{on "init_burnout"
	      {if rand 0.3
			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
	       }
	}
    {on fire "gun" 
		("low_speed_bullet")
		{set "gun"}{call "proj_probe"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{view start "zenite_smoke"}
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
			{delay 1	{call "spawn_shell"}}
			{delay 2	{view pause "zenite_smoke"}}
		}
	}
)
(define "100mm_2a70"
	{on "init_burnout"
	      {if rand 0.3
			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
	       }
	}
 	{on "init1_gun"
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
		{add_view	"tank_canon_fire_3_link"		"flashbarrel1"			"Foresight1"}
		{add_view	"dust_shot_normal_link"		"flashbarrel1"			"basis"}
	}
    {on fire "gun" 
		("low_speed_bullet")
      	{set "gun"}{call "proj_probe"}
;		{spawn "dust_shot_normal" "basis"}
;    	{spawn "tank_canon_fire_3" "Foresight1" x}
		{view start "flashbarrel_gun"}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{view start "zenite_smoke"}
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
			{delay 1.5 {call "spawn_shell"}}
			{delay 2	{view pause "zenite_smoke"}}
		}
	}
)
(define "m68_type_gun"
	{on "init_gun"
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
	}
	("90-105mm_gun_with_cm")
	("no_gilza_ejection")
)
(define "u5ts_type_gun"
	{on "init_gun"
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
	}
	("110-130mm_gun_with_cm")
	("110-130mm_gilza")
)
(define "2a46_type_gun"
	{on "init_gun"
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
	}
	("110-130mm_gun_with_cm")
	("2a46_poddon")
)
(define "2a46_type_gun_nogilz"
	{on "init_gun"
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
	}
	("110-130mm_gun_with_cm")
	("no_gilza_ejection")
)
(define "m256_type_gun"
	{on "init_burnout"
	      {if rand 0.3
			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
	       }
	}
 	{on "init1_gun"
		{add_view 	"smoke_ejector_fast" 	"zenite_smoke" 		"foresight1"}
		{add_view	"tank_canon_fire_3_link"		"flashbarrel1"			"Foresight1"}
		{add_view	"dust_shot_big_link"		"flashbarrel1"			"basis"}
	}
	{on fire "gun" 
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.2 "shell_off"
			{view start "zenite_smoke"}
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
			{delay 0.8 {view pause "zenite_smoke"}}
		}
		{set "gun"}{call "proj_probe"}
;		{spawn "dust_shot_big" "basis"}
;		{spawn "tank_canon_fire_3" "Foresight1" x}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
	}
)
;=======================ATGM=============================
(define "custom_single_launcher"
	{on "init_%weapon"
		{add_view	"rok_tail"	"rok_tail_%weapon"	"%tail"}
		{add_view	"startsmoke_link"	"rok_tail_%weapon"	"%foresight"}
	}
	{on fire "%weapon" overload
		("low_speed_bullet")
		{view start "rok_tail_%weapon"}
		{delay 0.4 {view pause "rok_tail_%weapon"}}
;		{spawn "startsmoke" "%foresight" x}
		{delay 0.1 {spawn "%missile_carrier" "%foresight"   x}}
		("cw_check_shooting" weap_id(%weapon))
	}
)
(define "atgm_single_launcher"
	{on "init_%weapon"
		{add_view	"rok_tail"	"rok_tail_%weapon"	"%tail"}
		{add_view	"startsmoke_link"	"rok_tail_%weapon"	"%foresight"}
		{add_view	"startsmoke_link"	"rok_tail_%weapon"	"%tail"}
	}
	{on fire "%weapon" overload
		("low_speed_bullet")
		{view start "rok_tail_%weapon"}
;		{spawn "startsmoke" "%foresight" x}
;		{spawn "startsmoke" "%tail" x}
		{set "%weapon"}{call "proj_probe"}
		{delay 0.4 {view pause "rok_tail_%weapon"}}
		("cw_check_shooting" weap_id(%weapon))
		{delay 0.2 {call "spawn_shell"}}
	}
)
(define "custom_multi_launcher"	;cпавн на шутере без выбора боеприпаса
	{on "init_%weapon"
		{add_view 	"rok_tail"		"%tail00"			"%tail00"}
		{add_view 	"rok_tail"		"%tail01"			"%tail01"}
		{add_view 	"rok_tail"		"%tail02"			"%tail02"}
		{add_view 	"rok_tail"		"%tail03"			"%tail03"}
		{add_view 	"rok_tail"		"%tail04"			"%tail04"}
		{add_view 	"rok_tail"		"%tail05"			"%tail05"}
		{add_view 	"rok_tail"		"%tail06"			"%tail06"}
		{add_view 	"rok_tail"		"%tail07"			"%tail07"}
		{add_view 	"startsmoke_link"		"%tail00"			"%tail00"}
		{add_view 	"startsmoke_link"		"%tail01"			"%tail01"}
		{add_view 	"startsmoke_link"		"%tail02"			"%tail02"}
		{add_view 	"startsmoke_link"		"%tail03"			"%tail03"}
		{add_view 	"startsmoke_link"		"%tail04"			"%tail04"}
		{add_view 	"startsmoke_link"		"%tail05"			"%tail05"}
		{add_view 	"startsmoke_link"		"%tail06"			"%tail06"}
		{add_view 	"startsmoke_link"		"%tail07"			"%tail07"}
		{add_view	"startsmoke_link"	"%tail00"	"%shooter00"}
		{add_view	"startsmoke_link"	"%tail01"	"%shooter01"}
		{add_view	"startsmoke_link"	"%tail02"	"%shooter02"}
		{add_view	"startsmoke_link"	"%tail03"	"%shooter03"}
		{add_view	"startsmoke_link"	"%tail04"	"%shooter04"}
		{add_view	"startsmoke_link"	"%tail05"	"%shooter05"}
		{add_view	"startsmoke_link"	"%tail06"	"%shooter06"}
		{add_view	"startsmoke_link"	"%tail07"	"%shooter07"}
	}
	{on fire "%weapon" overload
		(define "fire_barrel"
			name "%0"
				{delay 0.1 {spawn "%missile_carrier" "%shooter%0"   x}}
				{view start "%tail%0"}
;				{spawn "startsmoke" "%shooter%0" x}
;				{spawn "startsmoke" "%tail%0" x}
				{delay 0.4
					{view pause "%tail%0"}
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
		("cw_check_shooting" weap_id(%weapon))
	}
)
(define "custom_multi_vertlauncher"	;cпавн на шутере без выбора боеприпаса
	{on "init_%weapon"
		{add_view 	"%tailfx"		"%tail00"			"%tail00"}
		{add_view 	"%tailfx"		"%tail01"			"%tail01"}
		{add_view 	"%tailfx"		"%tail02"			"%tail02"}
		{add_view 	"%tailfx"		"%tail03"			"%tail03"}
		{add_view 	"%tailfx"		"%tail04"			"%tail04"}
		{add_view 	"%tailfx"		"%tail05"			"%tail05"}
		{add_view 	"%tailfx"		"%tail06"			"%tail06"}
		{add_view 	"%tailfx"		"%tail07"			"%tail07"}
		{add_view 	"startsmoke_vert_link"		"%tail00"			"%tail00"}
		{add_view 	"startsmoke_vert_link"		"%tail01"			"%tail01"}
		{add_view 	"startsmoke_vert_link"		"%tail02"			"%tail02"}
		{add_view 	"startsmoke_vert_link"		"%tail03"			"%tail03"}
		{add_view 	"startsmoke_vert_link"		"%tail04"			"%tail04"}
		{add_view 	"startsmoke_vert_link"		"%tail05"			"%tail05"}
		{add_view 	"startsmoke_vert_link"		"%tail06"			"%tail06"}
		{add_view 	"startsmoke_vert_link"		"%tail07"			"%tail07"}
		{add_view	"startsmoke_vert_link"	"%tail00"	"%shooter00"}
		{add_view	"startsmoke_vert_link"	"%tail01"	"%shooter01"}
		{add_view	"startsmoke_vert_link"	"%tail02"	"%shooter02"}
		{add_view	"startsmoke_vert_link"	"%tail03"	"%shooter03"}
		{add_view	"startsmoke_vert_link"	"%tail04"	"%shooter04"}
		{add_view	"startsmoke_vert_link"	"%tail05"	"%shooter05"}
		{add_view	"startsmoke_vert_link"	"%tail06"	"%shooter06"}
		{add_view	"startsmoke_vert_link"	"%tail07"	"%shooter07"}
	}
	{on fire "%weapon" overload
		{volumes "gun_recoil" enable blast}
		{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
		{delay 0.5 {volumes "gun_recoil" disable blast}}

		(define "fire_barrel"
			name "%0"
				{view start "%tail%0"}
;				{spawn "startsmoke_vert" "%shooter%0" x}
;				{spawn "startsmoke" "%tail%0" x}
				{bone show "missile_vis_%0"}
				{delay 0.05
					{bone show "missile_vis_a_%0"}
				}
				{delay 0.38
					{bone hide "missile_vis_%0"}
					{bone hide "missile_vis_a_%0"}
					{view pause "%tail%0"}
					{spawn "%missile_carrier" "%shooter%0" x }
				}
				{delay 0.45
					{ani_play "fire_restore"}
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
		("cw_check_shooting" weap_id(%weapon))
	}
)
(define "custom_sh_vertlauncher"	;cпавн на шутере с выбором боеприпаса (визуал одного типа)
	{on "init_%weapon"
		{add_view 	"%tailfx"		"%tail00"			"%tail00"}
		{add_view 	"%tailfx"		"%tail01"			"%tail01"}
		{add_view 	"%tailfx"		"%tail02"			"%tail02"}
		{add_view 	"%tailfx"		"%tail03"			"%tail03"}
		{add_view 	"%tailfx"		"%tail04"			"%tail04"}
		{add_view 	"%tailfx"		"%tail05"			"%tail05"}
		{add_view 	"%tailfx"		"%tail06"			"%tail06"}
		{add_view 	"%tailfx"		"%tail07"			"%tail07"}
		{add_view 	"startsmoke_vert_link"		"%tail00"			"%tail00"}
		{add_view 	"startsmoke_vert_link"		"%tail01"			"%tail01"}
		{add_view 	"startsmoke_vert_link"		"%tail02"			"%tail02"}
		{add_view 	"startsmoke_vert_link"		"%tail03"			"%tail03"}
		{add_view 	"startsmoke_vert_link"		"%tail04"			"%tail04"}
		{add_view 	"startsmoke_vert_link"		"%tail05"			"%tail05"}
		{add_view 	"startsmoke_vert_link"		"%tail06"			"%tail06"}
		{add_view 	"startsmoke_vert_link"		"%tail07"			"%tail07"}
		{add_view	"startsmoke_vert_link"	"%tail00"	"%shooter00"}
		{add_view	"startsmoke_vert_link"	"%tail01"	"%shooter01"}
		{add_view	"startsmoke_vert_link"	"%tail02"	"%shooter02"}
		{add_view	"startsmoke_vert_link"	"%tail03"	"%shooter03"}
		{add_view	"startsmoke_vert_link"	"%tail04"	"%shooter04"}
		{add_view	"startsmoke_vert_link"	"%tail05"	"%shooter05"}
		{add_view	"startsmoke_vert_link"	"%tail06"	"%shooter06"}
		{add_view	"startsmoke_vert_link"	"%tail07"	"%shooter07"}
	}
	{on fire "%weapon" overload
		{volumes "gun_recoil" enable blast}
		{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
		{delay 0.5 {volumes "gun_recoil" disable blast}}

		(define "fire_barrel"
			name "%0"
				{set "%weapon"}{call "proj_probe"}
				{view start "%tail%0"}
;				{spawn "startsmoke_vert" "%shooter%0" x}
;				{spawn "startsmoke" "%tail%0" x}
				{bone show "missile_vis_%0"}
				{delay 0.05
					{bone show "missile_vis_a_%0"}
				}
				{delay 0.38
					{bone hide "missile_vis_%0"}
					{bone hide "missile_vis_a_%0"}
					{view pause "%tail%0"}
				}
				{delay 0.45
					{ani_play "fire_restore"}
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
		("cw_check_shooting" weap_id(%weapon))
	}
)
(define "custom_sh_vertlauncher_ej"	;cпавн на шутере с выбором боеприпаса (визуал одного типа, минометный старт)
	{on "init_%weapon"
		{add_view 	"%tailfx"		"%tail00"			"%tail00"}
		{add_view 	"%tailfx"		"%tail01"			"%tail01"}
		{add_view 	"%tailfx"		"%tail02"			"%tail02"}
		{add_view 	"%tailfx"		"%tail03"			"%tail03"}
		{add_view 	"%tailfx"		"%tail04"			"%tail04"}
		{add_view 	"%tailfx"		"%tail05"			"%tail05"}
		{add_view 	"%tailfx"		"%tail06"			"%tail06"}
		{add_view 	"%tailfx"		"%tail07"			"%tail07"}
		{view pause "%tail00"} {view hide "%tail00"}
		{view pause "%tail01"} {view hide "%tail01"}
		{view pause "%tail02"} {view hide "%tail02"}
		{view pause "%tail03"} {view hide "%tail03"}
		{view pause "%tail04"} {view hide "%tail04"}
		{view pause "%tail05"} {view hide "%tail05"}
		{view pause "%tail06"} {view hide "%tail06"}
		{view pause "%tail07"} {view hide "%tail07"}
	}
	{on fire "%weapon" overload
		{volumes "gun_recoil" enable blast}
		{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
		{delay 0.5 {volumes "gun_recoil" disable blast}}

		(define "fire_barrel"
			name "%0"
				{set "%weapon"}{call "proj_probe"}
				{delay 0.2 
					{bone show "missile_vis_%0"}
					{delay 0.1
						{bone show "missile_vis_a_%0"}
					}
					{delay 0.35 
						{view start "%tail%0"}
						{view show "%tail%0"}
					
					}
					{delay 0.35 {spawn "tank_canon_fire_small" "%tail%0" x}}
					{delay 0.95
						{bone hide "missile_vis_%0"}
						{bone hide "missile_vis_a_%0"}
						{view pause "%tail%0"}
						{view hide "%tail%0"}
					}
					{delay 1.05
						{ani_play "fire_restore"}
					}
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
		("cw_check_shooting" weap_id(%weapon))
	}
)
(define "atgm_multi_launcher"	;Спавн на форесайте, не на шутере!
	{on "init_%weapon"
		{add_view 	"rok_tail"		"%tail00"			"%tail00"}
		{add_view 	"rok_tail"		"%tail01"			"%tail01"}
		{add_view 	"rok_tail"		"%tail02"			"%tail02"}
		{add_view 	"rok_tail"		"%tail03"			"%tail03"}
		{add_view 	"rok_tail"		"%tail04"			"%tail04"}
		{add_view 	"rok_tail"		"%tail05"			"%tail05"}
		{add_view 	"rok_tail"		"%tail06"			"%tail06"}
		{add_view 	"rok_tail"		"%tail07"			"%tail07"}
		{add_view 	"startsmoke_link"		"%tail00"			"%tail00"}
		{add_view 	"startsmoke_link"		"%tail01"			"%tail01"}
		{add_view 	"startsmoke_link"		"%tail02"			"%tail02"}
		{add_view 	"startsmoke_link"		"%tail03"			"%tail03"}
		{add_view 	"startsmoke_link"		"%tail04"			"%tail04"}
		{add_view 	"startsmoke_link"		"%tail05"			"%tail05"}
		{add_view 	"startsmoke_link"		"%tail06"			"%tail06"}
		{add_view 	"startsmoke_link"		"%tail07"			"%tail07"}
		{add_view	"startsmoke_link"	"%tail00"	"%foresight"}
		{add_view	"startsmoke_link"	"%tail01"	"%foresight"}
		{add_view	"startsmoke_link"	"%tail02"	"%foresight"}
		{add_view	"startsmoke_link"	"%tail03"	"%foresight"}
		{add_view	"startsmoke_link"	"%tail04"	"%foresight"}
		{add_view	"startsmoke_link"	"%tail05"	"%foresight"}
		{add_view	"startsmoke_link"	"%tail06"	"%foresight"}
		{add_view	"startsmoke_link"	"%tail07"	"%foresight"}
	}
	{on fire "%weapon" overload
		("low_speed_bullet")
		{set "%weapon"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "%tail%0"}
;				{spawn "startsmoke" "%foresight" x}
;				{spawn "startsmoke" "%tail%0" x}
				{delay 0.4
					{view pause "%tail%0"}
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
		("cw_check_shooting" weap_id(%weapon))
	}
)
(define "custom_sh_multi_launcher"	;Спавн на шутере!
	{on "init_%weapon"
		{add_view 	"rok_tail"		"%tail00"			"%tail00"}
		{add_view 	"rok_tail"		"%tail01"			"%tail01"}
		{add_view 	"rok_tail"		"%tail02"			"%tail02"}
		{add_view 	"rok_tail"		"%tail03"			"%tail03"}
		{add_view 	"rok_tail"		"%tail04"			"%tail04"}
		{add_view 	"rok_tail"		"%tail05"			"%tail05"}
		{add_view 	"rok_tail"		"%tail06"			"%tail06"}
		{add_view 	"rok_tail"		"%tail07"			"%tail07"}
		{add_view 	"startsmoke_link"		"%tail00"			"%tail00"}
		{add_view 	"startsmoke_link"		"%tail01"			"%tail01"}
		{add_view 	"startsmoke_link"		"%tail02"			"%tail02"}
		{add_view 	"startsmoke_link"		"%tail03"			"%tail03"}
		{add_view 	"startsmoke_link"		"%tail04"			"%tail04"}
		{add_view 	"startsmoke_link"		"%tail05"			"%tail05"}
		{add_view 	"startsmoke_link"		"%tail06"			"%tail06"}
		{add_view 	"startsmoke_link"		"%tail07"			"%tail07"}
		{add_view	"startsmoke_link"	"%tail00"	"%shooter00"}
		{add_view	"startsmoke_link"	"%tail01"	"%shooter01"}
		{add_view	"startsmoke_link"	"%tail02"	"%shooter02"}
		{add_view	"startsmoke_link"	"%tail03"	"%shooter03"}
		{add_view	"startsmoke_link"	"%tail04"	"%shooter04"}
		{add_view	"startsmoke_link"	"%tail05"	"%shooter05"}
		{add_view	"startsmoke_link"	"%tail06"	"%shooter06"}
		{add_view	"startsmoke_link"	"%tail07"	"%shooter07"}
	}
	{on fire "%weapon" overload
		("low_speed_bullet")
		
		(define "fire_barrel"
			name "%0"
				{view start "%tail%0"}
;				{spawn "startsmoke" "%shooter%0" x}
;				{spawn "startsmoke" "%tail%0" x}
				{set "%weapon"}{call "proj_probe"}
				{delay 0.4
					{view pause "%tail%0"}
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
		("cw_check_shooting" weap_id(%weapon))
	}
)

;=======================Other=============================
(define "shtora_smoke_mortar"
	{on fire "mgun%mgun_id" overload
		{spawn "startsmoke" "smokegun_rot%mgun_id" x}
		{spawn "smoke_shell_fly" "smokegun_rot%mgun_id" x 
			{impulse up 10 2 forward 100 rnd_dir 15 com}
			{gravity 0.9}
			{delay 0.2
				{spawn "ex_smokeshell"}
				{spawn "smoke_volume"}
				{delete}
			}
		}
	}
)
(define "afganit_smoke_mortar"
	{on fire "mgun%mgun_id" overload
		
		(define "afganit_smoke_shell"
		  name "%0"
			{spawn "startsmoke"  "Shooter%side_%0" x }
			{spawn "smoke_shell_fly" "Shooter%side_%0" x 
				{impulse up 10 2 forward 100 rnd_dir 15 com}
				{gravity 0.9}
				{delay 0.2
					{spawn "ex_smokeshell"}
					{spawn "smoke_volume"}
					{delete}
				}
			}
		)
		(define "afganit_decoy_shell"
		  name "%0"
			{spawn "startsmoke"  "Shooter%side_%0" x }
			{spawn "smoke_shell_fly" "Shooter%side_%0" x 
				{impulse up 20 2 rnd_dir 5 com}
				{gravity 0.9}
				{delay 0.15
					{add_view	"_chaff_fly"	"chaff1"			"body"}
					{add_view	"_chaff_fly"	"chaff2"			"body"}
					{view start "chaff1"}
					{view start "chaff2"}
				}
				{delay 0.2
					{spawn "ex_air_sm"}
;					{spawn "#flare_patron" {impulse up 3 1 rnd_dir 5 com}}
;					{spawn "#flare_patron" {impulse up 3 1 rnd_dir 5 com}}
					{if rand 0.2	{spawn "proj_point_usa_active"
						{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}
					{if rand 0.2	{spawn "proj_point_usa_active"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}					
					{if rand 0.2	{spawn "proj_point_rus_active"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}	
					{if rand 0.2	{spawn "proj_point_rus_active"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}						
					{if rand 0.2	{spawn "proj_point_usa_laser"
						{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}
					{if rand 0.2	{spawn "proj_point_usa_laser"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}					
					{if rand 0.2	{spawn "proj_point_rus_laser"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}	
					{if rand 0.2	{spawn "proj_point_rus_laser"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}						
					{if rand 0.2	{spawn "proj_point_usa_other"
						{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}
					{if rand 0.2	{spawn "proj_point_usa_other"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}					
					{if rand 0.2	{spawn "proj_point_rus_other"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}	
					{if rand 0.2	{spawn "proj_point_rus_other"
							{impulse up 5 1 rnd_dir 15}	{gravity 0.5} {kill_delay "normal_hide" }}}		
					{delete}
				}
			}
		)
		{if ("afganit_smoke_shell" args 00)
		else ("afganit_decoy_shell" args 01)
		else ("afganit_smoke_shell" args 02)
		else ("afganit_decoy_shell" args 03)		
		else ("afganit_smoke_shell" args 04)
		else ("afganit_decoy_shell" args 05)		
		else ("afganit_smoke_shell" args 06)
		else ("afganit_decoy_shell" args 07)		
		else ("afganit_smoke_shell" args 08)
		else ("afganit_decoy_shell" args 09)		
		else ("afganit_smoke_shell" args 10)
		else ("afganit_decoy_shell" args 11)		
		else ("afganit_smoke_shell" args 12)
		else ("afganit_decoy_shell" args 13)		
		else ("afganit_smoke_shell" args 14)
		else ("afganit_decoy_shell" args 15)		
		else ("afganit_smoke_shell" args 16)
		else ("afganit_decoy_shell" args 17)		
		else ("afganit_smoke_shell" args 18)
		else ("afganit_decoy_shell" args 19)		
		else ("afganit_smoke_shell" args 20)
		else ("afganit_decoy_shell" args 21)		
		else ("afganit_smoke_shell" args 22)
		else ("afganit_decoy_shell" args 23)		
		}
	}
)
(define "auto_gren_launcher"
    	{on fire "%mgun" overload
		;{spawn "startsmoke" inv_normal}
		("cw_check_shooting" weap_id(%mgun))
	}
)
;=======================AA mgun=============================
(define "zpu_one_hatch"
	{on "cwsh_update_hatch" overload
		("update_hatch" wind(false) place(%gunner))
	}
	{on "zpu_%gunner_hatch_open"
		{ani_wind "%hatch_anim" end}
	}
	{on "zpu_%gunner_hatch_close"
		{ani_wind "%hatch_anim" begin}
	}
	{on "zpu_%gunner_hatch_opening"
		{ani_play "%hatch_anim" resume}
	}
	{on "zpu_%gunner_hatch_closing"
		{ani_play "%hatch_anim" -1 resume}
	}
)
(define "zpu_params"
	("commonzpu_params" gunner(%gunner) zpu_mgun(%zpu_mgun) anim(%anim) pose(%pose))
	("zpu_one_hatch" gunner(%gunner) hatch_anim(open))
)
(define "doublezpu_params"
	{on "cwsh_update_hatch" overload
		("update_hatch" wind(false) place(%gunner))
		("update_hatch" wind(false) place(%secgunner))
	}
	{on "update_hatch_on_spawn"  overload
		("update_hatch" wind(true) place(%gunner))
		("update_hatch" wind(true) place(%secgunner))
		{tags remove "cw_panorama_work"}
		{call "update_cw_panorama"}
	}
	("update_hatch_event" event(operatable on) place(%secgunner))
	("update_hatch_event" event(operatable off) place(%secgunner))
	("update_hatch_event" event(crew in) place(%secgunner))
	("update_hatch_event" event(crew out) place(%secgunner))
	{on "update_zpu"
		{if tagged "cwsh_zpu_off"
			{with_linked_entity "%gunner" {ani_wind "%anim" end}}
			{with_linked_entity "%secgunner" {ani_wind "%secanim" end}}
		}
		{kill_delay "cwsh_disable_zpu"}
		{if tagged "cwsh_tempdisable_zpu"
			{delay 15 "cwsh_disable_zpu"
			     {if  tagged "cwsh_tempdisable_zpu"
				{tags remove "cwsh_tempdisable_zpu"}
				{call "cwsh_enable_zpu"}
			     }
			}
		}
	}
	{on "cwsh_gunner_in" overload
		{with_linked_entity "%gunner" {ani_play "%anim"}}
		{with_linked_entity "%secgunner" {ani_play "%secanim"}}
	}
	{on "cwsh_gunner_out" overload
		{with_linked_entity "%gunner" {ani_play "%anim" -1}}
		{with_linked_entity "%secgunner" {ani_play "%secanim" -1}}
		{delay 1.5
		   {if not tagged "cwsh_tempdisable_zpu"
		     {if not tagged "cwsh_zpu_off"
			{with_linked_entity "%gunner" {ani_wind "%pose" end}}
			{with_linked_entity "%secgunner" {ani_wind "%secpose" end}}
		     }
		   }
		}
	}
	{on "zpu_%gunner_hatch_open"
		{ani_wind "%hatch_anim" end}
	}
	{on "zpu_%gunner_hatch_close"
		{ani_wind "%hatch_anim" begin}
	}
	{on "zpu_%gunner_hatch_opening"
		{ani_play "%hatch_anim" resume}
	}
	{on "zpu_%gunner_hatch_closing"
		{ani_play "%hatch_anim" -1 resume}
	}
	{on "zpu_%secgunner_hatch_open"
		{ani_wind "%sechatch_anim" end}
	}
	{on "zpu_%secgunner_hatch_close"
		{ani_wind "%sechatch_anim" begin}
	}
	{on "zpu_%secgunner_hatch_opening"
		{ani_play "%sechatch_anim" resume}
	}
	{on "zpu_%secgunner_hatch_closing"
		{ani_play "%sechatch_anim" -1 resume}
	}
	
	{on "update_%zpu_mgun" overload
	     {if work "%zpu_mgun" 
	          {if tagged "cwsh_zpu_off"
					{weapon_work "%zpu_mgun" 0}
				else {inherited}
	           }
	     }
	}
	{on "update_%seczpu_mgun" overload
	     {if work "%seczpu_mgun" 
	          {if tagged "cwsh_zpu_off"
					{weapon_work "%seczpu_mgun" 0}
				else {inherited}
	           }
	     }
	}

)
(define "radar_params"
	{on break
		{if component "%triplex_name" {call "cwsh_radar_off"}}
	}
	{on repair
		{if component "%triplex_name" {call "cwsh_radar_on"}}
	}
	{on "cwsh_radar_on"
		{if work "%triplex_name"
			{ani_play "%anim_rotate" loop}
			{delay 0.1 {ani_play "%visor" -1}}
			{with_linked_entity "vehicle9"
				{call "start"}
			}
		}
	}
	{on "cwsh_radar_off"
		{ani_stop "%anim_rotate"}
		{delay 0.1 {ani_play "%visor"}}
		{with_linked_entity "vehicle9"
			{call "stop"}
		}
	}
)
(define "radar_lifting90_params"
	{on break
		{if component "%triplex_name" {call "cwsh_radar_off"}}
	}
	{on repair
		{if component "%triplex_name" {call "cwsh_radar_on"}}
	}
	{on "cwsh_radar_on"
;		{delay 0.1
		 {if flag "radar_up"
	      {if not tagged "stabilizer_damaged"
	         {if work "%triplex_name"
				{ani_play "%anim_rotate" loop}
				{delay 0.1 {ani_play "%visor" -1}}
				{with_linked_entity "vehicle9"
					{call "start"}
				}
	         }
	      }
		 }
;		}
	}
	{on "emit_antiradar"
;		{add_view	"%marker"	"antirad_generator"		"basis"	}
;		{view start "antirad_generator"}
;		{view show "antirad_generator"}
	}
	{on animation_end "%anim_lift"
		{if not tagged "radar_off"
	     {call "cwsh_radar_on"}
		}
	}
	{on "cwsh_radar_off"
		{ani_stop "%anim_rotate"}
		{delay 0.1 {ani_play "%visor"}}
		{with_linked_entity "vehicle9"
			{call "stop"}
		}
	}
	{on operatable on
	   {if work "%triplex_name"
		{kill_delay "radar_lift"}
		{if not flag "radar_up"
			{ani_play "%anim_lift" callback}
			{set "radar_up" 1}
		}
	   }
	}
	{on operatable off
		{delay 0.1 "radar_lift"
		      {if flag "radar_up"
				{set "radar_up" 0}
				{ani_play "%anim_lift" -1}
		     }
		}
	}
)
(define "radar_lifting90_double_params"
	{on break
		{if component "%triplex_name" {call "cwsh_radar_off"}}
		{if component "%triplex1_name" {call "cwsh_radar_off"}}
	}
	{on repair
		{if component "%triplex_name" {call "cwsh_radar_on"}}
		{if component "%triplex1_name" {call "cwsh_radar_on"}}
	}
	{on "cwsh_radar_on"
;		{delay 0.1
		 {if flag "radar_up"
	      {if not tagged "stabilizer_damaged"
	         {if work "%triplex_name"
				{ani_play "%anim_rotate" loop}
				{delay 0.1 {ani_play "%visor" -1}}
				{with_linked_entity "vehicle9"
					{call "start"}
				}
	         }
	         {if work "%triplex1_name"
				{ani_play "%anim_rotate1" loop}
				{delay 0.1 {ani_play "%visor1" -1}}
				{with_linked_entity "vehicle9"
					{call "start"}
				}
	         }
	      }
		 }
;		}
	}
	{on "emit_antiradar"
;		{add_view	"%marker"	"antirad_generator"		"basis"	}
;		{view start "antirad_generator"}
;		{view show "antirad_generator"}
	}
	{on animation_end "%anim_lift"
		{if not tagged "radar_off"
	     {call "cwsh_radar_on"}
		}
	}
	{on "cwsh_radar_off"
		{ani_stop "%anim_rotate"}
		{ani_stop "%anim_rotate1"}
		{delay 0.1 {ani_play "%visor"}}
		{delay 0.1 {ani_play "%visor1"}}
		{with_linked_entity "vehicle9"
			{call "stop"}
		}
	}
	{on operatable on
	   {if work "%triplex_name"
		{kill_delay "radar_lift"}
		{if not flag "radar_up"
			{ani_play "%anim_lift" callback}
			{set "radar_up" 1}
		}
	   }
	   {if work "%triplex1_name"
		{kill_delay "radar_lift"}
		{if not flag "radar_up"
			{ani_play "%anim_lift" callback}
			{set "radar_up" 1}
		}
	   }
	}
	{on operatable off
		{delay 0.1 "radar_lift"
		      {if flag "radar_up"
				{set "radar_up" 0}
				{ani_play "%anim_lift" -1}
		     }
		}
	}
)
;=======================Smokes=============================
(define "smokegun_as90"
	{on fire "%smokegun" overload
		{spawn "startsmoke" inv_normal}
		{if name "00" {spawn "smoke_probe" inv_normal {tags add "0_0"}}
		else name "01" {spawn "smoke_probe" inv_normal {tags add "0_m20"}}
		else name "02" {spawn "smoke_probe" inv_normal {tags add "0_20"}}
		else name "03" {spawn "smoke_probe" inv_normal {tags add "15_m10"}}
		else name "04" {spawn "smoke_probe" inv_normal {tags add "15_10"}}
		else {spawn "smoke_probe" inv_normal {tags add "0_0"}}
		}
	}
)
(define "smokegun_quad"
	{on fire "%smokegun" overload
		{spawn "startsmoke" inv_normal}
		{if name "00" {spawn "smoke_probe" inv_normal {tags add "15_m10"}}
		else name "01" {spawn "smoke_probe" inv_normal {tags add "15_10"}}
		else name "02" {spawn "smoke_probe" inv_normal {tags add "0_20"}}
		else name "03" {spawn "smoke_probe" inv_normal {tags add "0_m20"}}
		else {spawn "smoke_probe" inv_normal {tags add "0_0"}}
		}
	}
)
(define "smokegun_nospread"
	{on fire "%smokegun" overload
		{spawn "startsmoke" inv_normal}
		{spawn "smoke_probe" inv_normal {tags add "0_0"}}
	}
)
;=======================Random texmod=============================
;At least one texmod variant should be left blank, or else default texmod will not present at all
(define "rand_texmod_1"
	{if not game "cooperative"	;правка не для сингла
		{tags add "need_texmod"}
		{delay 0.3
			{if game_param "biom" "snow" or game_param "biom" "desert"	;we don't have much desert or winter texmods except basic one
			else
				{if tagged "texmod1" {tex_mod "%name1"}		{tex_mod "d1"}
				else tagged "texmod2"						{tex_mod "d2"}
				else tagged "texmod3" {tex_mod "%name1"}	{tex_mod "d3"}
				else tagged "texmod4"						{tex_mod "d4"}
				}
			}
			{tags remove "need_texmod"}{tags remove "texmod1"}{tags remove "texmod2"}{tags remove "texmod3"}{tags remove "texmod4"}
		}
	}
)
(define "rand_texmod_2"
	{if not game "cooperative"	;правка не для сингла
		{tags add "need_texmod"}
		{delay 0.3
			{if game_param "biom" "snow" or game_param "biom" "desert"	;we don't have much desert or winter texmods except basic one
			else
				{if tagged "texmod1" {tex_mod "%name1"}		{tex_mod "d1"}
				else tagged "texmod2" {tex_mod "%name2"}	{tex_mod "d2"}
				else tagged "texmod3"						{tex_mod "d3"}
				else tagged "texmod4"						{tex_mod "d4"}
				}
			}
			{tags remove "need_texmod"}{tags remove "texmod1"}{tags remove "texmod2"}{tags remove "texmod3"}{tags remove "texmod4"}
		}
	}
)
(define "rand_texmod_3"
	{if not game "cooperative"	;правка не для сингла
		{tags add "need_texmod"}
		{delay 0.3
			{if game_param "biom" "snow" or game_param "biom" "desert"	;we don't have much desert or winter texmods except basic one
			else
				{if tagged "texmod1" {tex_mod "%name1"}		{tex_mod "d1"}
				else tagged "texmod2" {tex_mod "%name2"}	{tex_mod "d2"}
				else tagged "texmod3" {tex_mod "%name3"}	{tex_mod "d3"}
				else tagged "texmod4"						{tex_mod "d4"}
				}
			}
			{tags remove "need_texmod"}{tags remove "texmod1"}{tags remove "texmod2"}{tags remove "texmod3"}{tags remove "texmod4"}
		}
	}
)
(define "rand_texmod_0"	;if unit has tactical signs, but no proper texmods
	{if not game "cooperative"	;правка не для сингла
		{tags add "need_texmod"}
		{delay 0.3
			{if game_param "biom" "snow" or game_param "biom" "desert"	;we don't have much desert or winter texmods except basic one
			else
				{if tagged "texmod1"	{tex_mod "d1"}
				else tagged "texmod2"	{tex_mod "d2"}
				else tagged "texmod3"	{tex_mod "d3"}
				else tagged "texmod4"	{tex_mod "d4"}
				}
			}
			{tags remove "need_texmod"}{tags remove "texmod1"}{tags remove "texmod2"}{tags remove "texmod3"}{tags remove "texmod4"}
		}
	}
)