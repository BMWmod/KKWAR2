;SDL
;============================ TERRITORY HOLDER ============================
(define "territory_holder_apc"
	{cwe 0}			; capture enemy territory
	{cwa 1.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_commander_apc"
	{cwe 1.0}		; capture enemy territory
	{cwa 1.5} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_tanks"
	{cwe 0.0}		; capture enemy territory
	{cwa 0.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_tanks_bonus"
	{cwe 0.0}		; capture enemy territory
	{cwa 0.5} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_heavy_tanks"
	{cwe 0.0}		; capture enemy territory
	{cwa 2.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_heavy_tanks_bonus"
	{cwe 0.0}		; capture enemy territory
	{cwa 2.5} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_spg"
	{cwe 0.0}		; capture enemy territory
	{cwa 0.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_gun"
	{cwe 0.1}		; capture enemy territory
	{cwa 2.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_house"
	{cw		0 50 20 50}	; (range - weight) ...
	{cwe	1.0}		; capture enemy territory
	{cwa	1.0} 		; hold ally territory / support ally advancement
	{cwn	1.0} 		; capture neutral territory
)
(define "territory_holder_bunker"
	{cw		0 50 35 50}	; (range - weight) ...
	{cwe	1.0}		; capture enemy territory
	{cwa	1.0} 		; hold ally territory / support ally advancement
	{cwn	1.0} 		; capture neutral territory
)
(define "territory_holder_сommand_post"
	{cw		0 50 50 50}	; (range - weight) ...
	{cwe	1.0}		; capture enemy territory
	{cwa	1.0} 		; hold ally territory / support ally advancement
	{cwn	1.0} 		; capture neutral territory
)
(define "territory_holder_helper"
	{cw  	20 15 30 0}
	{cwe 	1.0}		; capture enemy territory
	{cwa 	1.0} 		; hold ally territory / support ally advancement
	{cwn 	1.0} 		; capture neutral territory
)
(define "territory_holder_airborne"
	{cwe 0}		; capture enemy territory
	{cwa 0} 		; hold ally territory / support ally advancement
	{cwn 0} 		; capture neutral territory
)
(define "territory_holder_marine"
	{cw  	15 5 20 0}
	{cwe 1.0}		; capture enemy territory
	{cwa 1.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)

;================================== SET =======================================
(define "generic_v"
    {charge 0}
	{score %sc}
	{cost %sc}
    {tags "%t"}
	{s %s}
    {cw %cw}
    {cp %cp}
	{level 1}
	{fore 1}
	{dont_unfog_by_territory}
	{spawn_distance 500}
)
;-------------------

(define "v_t"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "* ( mp2/%s/tankman:%n )"}
)
(define "v_t_n"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "* ( mp2/%na/tankman:%n )"}
)

(define "v_s"
    ("generic_v" sc(%sc) t(%t %s) cw(%cw) cp(%cp))
    {content "* ( mp2/%s/vehicle_supporter:%n )"}
)
(define "v_s_n"
    ("generic_v" sc(%sc) t(%t %s) cw(%cw) cp(%cp))
    {content "* ( mp2/%na/vehicle_supporter:%n )"}
)

(define "v_custom"
    ("generic_v" sc(%sc) t(%t %s) cw(%cw) cp(%cp))
    {content "* ( %crew )"}
)

(define "v_heli"
    ("generic_v" sc(%sc) t(%t %s) cw(%cw) cp(%cp))
    {content "* ( mp2/%s/vertpilot:%n )"}
)

(define "v_p"
    ("generic_v" sc(%sc) t(%t %s) cw(%cw) cp(%cp))
    {content "* ( mp2/%s/pilot:%n )"}
)

(define "v_t_inf"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%s/tankman:%n %secondcrew)"}
	{auto_recovering_time 60}
)
(define "v_vdv_inf"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%s/vdv_tankman:%n %secondcrew)"}
	{auto_recovering_time 60}
)
(define "v_t_inf_n"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%na/tankman:%n %secondcrew)"}
	{auto_recovering_time 60}
)

(define "v_s_inf"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%s/vehicle_supporter:%n %secondcrew)"}
	{auto_recovering_time 60}
)
(define "v_s_inf_n"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%na/vehicle_supporter:%n %secondcrew)"}
	{auto_recovering_time 60}
)
(define "v_heli_inf"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%s/vertpilot:%n %secondcrew)"}
	{auto_recovering_time 60}
)
(define "v_trailer"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%s/vehicle_supporter:%n ) %c2 ( %secondcrew )"}
	{main "%c2"}
)
(define "v_trailer_n"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%na/vehicle_supporter:%n ) %c2 ( %secondcrew )"}
	{main "%c2"}
)
	(include "vehicles_rus.inc")
	(include "vehicles_usa.inc")
	(include "vehicles_nato.inc")
	(include "vehicles_cn.inc")

;[House]_____________________________________________________________________________________________________________________________________________________________________
{"house_001_g2"		("territory_holder_house")}
{"house_001a_g2"	("territory_holder_house")}
{"house_001b_g2"	("territory_holder_house")}
{"house_40_g2"		("territory_holder_house")}
{"house_50_g2"		("territory_holder_house")}
{"house_60_g2"		("territory_holder_house")}
{"house_70_g2"		("territory_holder_house")}
{"house_80_g2"		("territory_holder_house")}
{"house_80a_g2"		("territory_holder_house")}
{"house_90_g2"		("territory_holder_house")}
{"house_d_001"		("territory_holder_house")}
{"house_d_002"		("territory_holder_house")}
{"house_d_003"		("territory_holder_house")}
{"house_d_003_1a"	("territory_holder_house")}
{"house_d_003_2a"	("territory_holder_house")}
{"house_d_004"		("territory_holder_house")}
{"house_d_004_p1"	("territory_holder_house")}
{"house_d_004_p2"	("territory_holder_house")}
{"house_d_004_p3"	("territory_holder_house")}
{"house_d_005"		("territory_holder_house")}
{"house_d_005_1"	("territory_holder_house")}
{"house_d_005_2"	("territory_holder_house")}
{"house_d_005_3"	("territory_holder_house")}
{"house_d_006"		("territory_holder_house")}
{"shed_village_g2"	("territory_holder_house")}
{"e_hangar_111_g2"	("territory_holder_house")}
{"barn_10"			("territory_holder_house")}
{"barn_20"			("territory_holder_house")}
{"barn_30"			("territory_holder_house")}
{"barn_40"			("territory_holder_house")}
{"barn_50"			("territory_holder_house")}
{"barn_60"			("territory_holder_house")}
{"build_ua_01"		("territory_holder_house")}
{"build_ua_02"		("territory_holder_house")}
{"build_ua_03"		("territory_holder_house")}
{"build_ua_04"		("territory_holder_house")}
{"build_ua_05"		("territory_holder_house")}
{"build_ua_06"		("territory_holder_house")}
{"build_ua_08"		("territory_holder_house")}
{"build_ua_07"		("territory_holder_house")}
{"build_vil_001"	("territory_holder_house")}
{"build_vil_004"	("territory_holder_house")}
{"build_vil_003"	("territory_holder_house")}
{"build_vil_004"	("territory_holder_house")}
{"house_uk_001"	    ("territory_holder_house")}
{"barn_ger01"	    ("territory_holder_house")}
{"house_ger01"	    ("territory_holder_house")}
{"house_ger02"	    ("territory_holder_house")}
{"house_ger03"	    ("territory_holder_house")}
{"house_ger04"	    ("territory_holder_house")}
{"house_ger05"	    ("territory_holder_house")}
{"house_ger06"	    ("territory_holder_house")}
{"house_ger07"	    ("territory_holder_house")}
{"house_ger08"	    ("territory_holder_house")}
{"france_mill"	    ("territory_holder_house")}
{"station001"	    ("territory_holder_house")}
{"station002"	    ("territory_holder_house")}
{"station003"	    ("territory_holder_house")}
{"station004"	    ("territory_holder_house")}
{"control_office_001"	    ("territory_holder_house")}
{"water_tower_001"	    ("territory_holder_house")}

;builds
{"med_point"	    ("territory_holder_house")}

;[bunker]_____________________________________________________________________________________________________________________________________________________________________
{"kiur_bunker_001"		("territory_holder_bunker")}
{"kiur_bunker_002"		("territory_holder_bunker")}
{"kiur_bunker_003"		("territory_holder_bunker")}
{"dot2_v"				("territory_holder_bunker")}
{"dot_small"			("territory_holder_bunker")}
{"dot_small_buid"		("territory_holder_bunker")}
{"dot_wood"				("territory_holder_bunker")}
{"dot_wood_buid"		("territory_holder_bunker")}
{"blindage_wood"		("territory_holder_сommand_post")}

;[Helpers]________________________________________________________________________________________________________________________________________________________________________

;[Helpers]________________________________________________________________________________________________________________________________________________________________________
{"fog_open_point"			cw{0}}
{"tagged_piece"				cw{0}}
{"missionwp"				cw{0}}
{"paratrooper_attach"		cw{0}}
{"parachute_lg40_box"		cw{0}}
{"air_strike_target"		cw{0}}
{"frontline_break"			cw{0}}
{"icon_object"				cw{0}}
{"structure_object"			cw{0}}
{"capture_object"			("territory_holder_helper")}
{"cwps3_proj_point"			cw{0}}
{"cwps3_proj_point_air"		cw{0}}
{"proj_point_rus_large_antirad_spawner"		cw{0}}
{"proj_point_rus_antirad"		cw{0}}
{"proj_point_rus_antirad_spawner"		cw{0}}
{"proj_point_usa_antirad_spawner"		cw{0}}
{"proj_point_usa_antirad"		cw{0}}
{"proj_point_usa_large_antirad"		cw{0}}
{"proj_point_usa_large_antirad_spawner"		cw{0}}
{"proj_point_usa_antirad"		cw{0}}

(define "missile"
	{"%m_carrier"
	{score 0}
    {cw 0}
	{dont_unfog_by_territory}
	}
	{"%m_impactor_link"
	{score 0}
    {cw 0}
	{dont_unfog_by_territory}
	}
)
(include "missile_mp.inc")