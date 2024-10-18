;=========CtA 
;{ZClipVisibility 0}

(define "declare_fire_volume"
	{Volume "fire%0"
		{able clear}
		{tags "fire"}
	}
	{Volume "smoke%0"
		{able clear}
		{tags "fire"}
	}
)
(define "declare_fire_volumes"
	{props "burning_old"}
	("declare_fire_volume" args 0)	("declare_fire_volume" args 1)
	("declare_fire_volume" args 2)	("declare_fire_volume" args 3)
	("declare_fire_volume" args 4)	("declare_fire_volume" args 5)
	("declare_fire_volume" args 6)	("declare_fire_volume" args 7)
	("declare_fire_volume" args 8)	("declare_fire_volume" args 9)
)
(define "armor_construction"
	{armor
		{setting "body"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold {pierce {calibre %calibre}}}
			{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
			{fragment_pass_threshold 1}
		}
		{setting "roof"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold {pierce {calibre %calibre}}}
			;{ray_cast_thickness}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
			{fragment_pass_threshold 1}
		}
	}
)

(define "bullet_pass_base"
	{armor
		{setting "body"
			{bullet_pass	{threshold %0}}
			{fragment_pass_threshold %1}
		}
		{setting "roof"
			{bullet_pass	{threshold %0}}
			{fragment_pass_threshold %1}
		}
	}
)
(define "bullet_pass"			("bullet_pass_base" args 100 1))
(define "bullet_pass_rpg"		("bullet_pass_base" args 50 1))
(define "bullet_pass_bullet"	("bullet_pass_base" args 10 0))

(define "blast_protection"
	{armor
		{setting "body"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold {blast {value %dmg}}}
			{fragment_pass_threshold 1}
		}
		{setting "roof"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold {blast {value %dmg}}}
			{fragment_pass_threshold 1}
		}
	}
)

(define "frag_grenade_protection"
	("blast_protection" dmg(6))
)

(define "armor_light"
	("armor_construction" calibre(10))   ; 
	("bullet_pass")
	{armor
		{setting "body"
			{threshold  
				{blast {value 10}}	; 57mm fg protection
			}
			{durability 
				{blast {value 25}}	; will broke down after 2-3 hits by 75mm fg
				{pierce {value 350}}			
			}
			{fragment_pass_threshold 1}
		}		
		{setting "roof"
			{threshold 
				{blast {value 10}}
			}
			{durability 
				{blast {value 10}}	; will broke down after 1 hit by 75mm fg
				{pierce {value 50}}			
			}
			{fragment_pass_threshold 1}
		}	
	}
)
(define "armor_stone_house"
	{armor
		{setting "body"
			{threshold_weakness_calibre 99}
			{bullet_pass	{threshold 300}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 70}}
			}
			{durability 
				{blast {value 90}}	; 
				{pierce {value 245}}			
			}
			{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			{threshold_weakness_calibre 99}
			{bullet_pass	{threshold 300}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 70}}
			}
			{durability 
				{blast {value 90}}	; 
				{pierce {value 245}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "armor_stone_house_roof"
	{armor
		{setting "body"
			{threshold_weakness_calibre 36}
			{bullet_pass	{threshold 99}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 13}}
			}
			{durability 
				{blast {value 16}}	; 
				{pierce {value 20}}			
			}
			{thickness 5}
			;{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			{threshold_weakness_calibre 36}
			{bullet_pass	{threshold 99}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 13}}
			}
			{durability 
				{blast {value 16}}	; 
				{pierce {value 20}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "damage_passer_pierce"
	{damage_passer
		{chance 1
			{pierce {value 0}}
		}
	}
)
(define "armor_brick_house"
	{armor
		{setting "body"
			("damage_passer_pierce")
			{threshold_weakness_calibre 80}
			{bullet_pass	{threshold 211}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 70}}
			}
			{durability 
				{blast {value 70}}	; 
				{pierce {value 215}}			
			}
			{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			("damage_passer_pierce")
			{threshold_weakness_calibre 80}
			{bullet_pass	{threshold 211}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 70}}
			}
			{durability 
				{blast {value 70}}	; 
				{pierce {value 215}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "armor_saman_house"
	{armor
		{setting "body"
			("damage_passer_pierce")
			{threshold_weakness_calibre 19}
			{bullet_pass	{threshold 131}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 36}}
			}
			{durability 
				{blast {value 12}}	; 
				{pierce {value 135}}			
			}
			{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			("damage_passer_pierce")
			{threshold_weakness_calibre 19}
			{bullet_pass	{threshold 131}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 36}}
			}
			{durability 
				{blast {value 12}}	; 
				{pierce {value 135}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "armor_saman_house_roof"
	{armor
		{setting "body"
			("damage_passer_pierce")
			{threshold_weakness_calibre 12}
			{bullet_pass	{threshold 80}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 8}}
			}
			{durability 
				{blast {value 5}}	; 
				{pierce {value 12}}			
			}
			{thickness 5}
			;{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			("damage_passer_pierce")
			{threshold_weakness_calibre 12}
			{bullet_pass	{threshold 80}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 8}}
			}
			{durability 
				{blast {value 5}}	; 
				{pierce {value 12}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "armor_log_house"
	{armor
		{setting "body"
			("damage_passer_pierce")
			{threshold_weakness_calibre 19}
			{bullet_pass	{threshold 99}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 36}}
			}
			{durability 
				{blast {value 7}}	; 
				{pierce {value 100}}			
			}
			{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			("damage_passer_pierce")
			{threshold_weakness_calibre 19}
			{bullet_pass	{threshold 99}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 36}}
			}
			{durability 
				{blast {value 7}}	; 
				{pierce {value 100}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "armor_plank_house"
	{armor
		{setting "body"
			("damage_passer_pierce")
			{threshold_weakness_calibre 12}
			{bullet_pass	{threshold 80}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 19}}
			}
			{durability 
				{blast {value 10}}	; 
				{pierce {value 28}}			
			}
			;{ray_cast_thickness}
			{thickness 5}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			("damage_passer_pierce")
			{threshold_weakness_calibre 12}
			{bullet_pass	{threshold 80}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 19}}
			}
			{durability 
				{blast {value 10}}	; 
				{pierce {value 28}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "armor_plank_house_roof"
	{armor
		{setting "body"
			("damage_passer_pierce")
			{threshold_weakness_calibre 8}
			{bullet_pass	{threshold 60}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 8}}
			}
			{durability 
				{blast {value 3}}	; 
				{pierce {value 10}}			
			}
			{thickness 5}
			;{ray_cast_thickness}
			{whole_wound}
			{volumes "body*"}
		}		
		{setting "roof"
			("damage_passer_pierce")
			{threshold_weakness_calibre 8}
			{bullet_pass	{threshold 60}}
			{fragment_pass_threshold 1}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 0}}	; 
				{pierce {calibre 8}}
			}
			{durability 
				{blast {value 3}}	; 
				{pierce {value 10}}			
			}
			{thickness 5}
			{whole_wound}
			{volumes "roof*"}
		}
	}
)
(define "armor_medium_base"
	("armor_construction" calibre(12))	; at rifles+
	("%name")
	{armor
		{setting "body"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 10}}	; 57mm fg protection 
				{pierce {value 0}}
			}
			{durability 
				{blast {value 25}}	; will broke down after 2-3 hits by 75mm fg
				{pierce {value 350}}			
			}
		}		
		{setting "roof"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold 
				;{blast {value 6}}
				{pierce {value 0}}
			}
			{durability 
				;{blast {value 10}}	; will broke down after 1 hit by 75mm fg
				{pierce {value 50}}			
			}
		}	
	}
)
(define "armor_medium"
	("armor_construction" calibre(30))	; 
	{armor
		{setting "body"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 15}}	; 57mm fg protection
			}
			{durability 
				{blast {value 50}}	; will broke down after 2-3 hits by 75mm fg
				{pierce {value 1400}}			
			}
			{fragment_pass_threshold 1}
		}		
		{setting "roof"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold 
				{blast {value 10}}
			}
			{durability 
				{blast {value 30}}	; will broke down after 1 hit by 75mm fg
				{pierce {value 200}}			
			}
			{fragment_pass_threshold 1}
		}	
	}
)
(define "armor_medium_first_floor"
	("armor_construction" calibre(12))	; at rifles+
	("bullet_pass")
	{armor
		{setting "body"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 10}}	; 57mm fg protection 
				{pierce {value 0}}
			}
			{durability 
				{blast {value 70}}	; will broke down after 2-3 hits by 75mm fg
				{pierce {value 350}}
			}
			{fragment_pass_threshold 1}
		}		
		{setting "roof"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold 
				;{blast {value 6}}
			}
			{durability 
				{blast {value 50}}	; will broke down after 1 hit by 75mm fg
				{pierce {value 50}}			
			}
			{fragment_pass_threshold 1}
		}	
	}
)
(define "armor_heavy"
	("armor_construction" calibre(50))	; guns only
	{armor
		{setting "body"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  
				{blast {value 30}}	; 57mm fg protection
			}
			{durability 
				{blast {value 30}}	; will broke down after 3-4 hits by 75mm fg
				{pierce {value 2000}}			
			}
			{fragment_pass_threshold 1}
		}
		{setting "roof"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold 
				{blast {value 15}}
			}
			{durability 
				{blast {value 40}}	; will broke down after 1 hit by mortar
				{pierce {value 300}}			
			}
			{fragment_pass_threshold 1}
		}
	}
)

(define "light_concrete"
	{armor
		{setting "body"
			{durability {pierce {koef 5}}}
		}
		{setting "roof"
			{durability {pierce {koef 5}}}
		}
	}
)

(define "armor_adjustable"
	{armor
		{setting "body"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold  {blast 	{value %thresh_fg}}
						{pierce {value %thresh_ap} {calibre %calibre}}}	
						
			{durability {blast 	{value %dur_fg}}
				 		{pierce {value %dur_ap}}}	
			{fragment_pass_threshold 1}
		}	
		{setting "roof"
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}
			{threshold {blast {value 6}}}
			{durability {blast {value 10}}}	
			{fragment_pass_threshold 1}
		}
	}
)

(define "armor_house_wood"
	("armor_medium")
	("frag_grenade_protection")
)

(define "armor_house_concrete"
	("armor_heavy")
	("frag_grenade_protection")
	("light_concrete")
)

(define "armor_house_concrete_light"
	("armor_medium")
	("frag_grenade_protection")
	("light_concrete")
)

(define "armor_house_wood_heavy"
	("armor_medium")
	("frag_grenade_protection")
)
(define "armor_bridge_concrete"
	("armor_heavy")
	("frag_grenade_protection")
	{armor
		{setting "body"
			{durability 
				{blast {value 12000}}; 12к=631вытсрел с 75мм 147в-150мм
			}
		}
	}
)
(define "armor_bridge_wood"
	("armor_heavy")
	("frag_grenade_protection")
	{armor
		{setting "body"
			{durability 
				{blast {value 15.4}}; 50мм снаряды ломают на 2+ выстрел, 75мм с первого выстрела
			}
		}
	}
)
(define "armor_ice"
	("armor_heavy")
	("frag_grenade_protection")
	{armor
		{setting "body"
			{durability 
				{blast {value 15.4}}; 50мм снаряды ломают на 2+ выстрел, 75мм с первого выстрела, повреждения отличаются
			}
		}
	}
)

(define "armor_barbwire"
	("armor_adjustable" thresh_fg(10) thresh_ap(0) dur_fg(58) dur_ap(100) calibre(12))
)


(define "armor_hedgehog"
	("armor_adjustable" thresh_fg(20) thresh_ap(45) dur_fg(30) dur_ap(150) calibre(57))
	("bullet_pass")
)

(define "armor_fabric"
	("armor_adjustable" thresh_fg(2) thresh_ap(0.5) dur_fg(5) dur_ap(10) calibre(0))
)

(define "armor_stack"
	("armor_adjustable" thresh_fg(2) thresh_ap(0.5) dur_fg(8) dur_ap(30) calibre(0))
)

(define "armor_glass"
	("armor_adjustable" thresh_fg(1) thresh_ap(0.2) dur_fg(4) dur_ap(30) calibre(0))
)

(define "armor_sandbag"
	("armor_adjustable" thresh_fg(10) thresh_ap(10) dur_fg(40) dur_ap(70) calibre(0))
	("bullet_pass")
)
(define "armor_watch_tower"
	("armor_adjustable" thresh_fg(0.1) thresh_ap(0.1) dur_fg(10) dur_ap(10) calibre(0))
	("bullet_pass")
)
(define "armor_dot_wood_roof"
	("armor_adjustable" thresh_fg(1) thresh_ap(45) dur_fg(30) dur_ap(150) calibre(0))
	("bullet_pass")
)
(define "armor_blindage_roof"
	("armor_adjustable" thresh_fg(2) thresh_ap(45) dur_fg(60) dur_ap(150) calibre(0))
	("bullet_pass")
)
(define "armor_sandbag_woodbeam"
	("armor_adjustable" thresh_fg(10) thresh_ap(10) dur_fg(40) dur_ap(80) calibre(0))
	("bullet_pass")
)
(define "armor_post"
	("armor_adjustable" thresh_fg(4) thresh_ap(5) dur_fg(20) dur_ap(20) calibre(10))
)
(define "armor_wires"
	("armor_adjustable" thresh_fg(4) thresh_ap(5) dur_fg(12) dur_ap(20) calibre(0))
)
(define "armor_fence_wood"
	("armor_adjustable" thresh_fg(5) thresh_ap(3) dur_fg(8) dur_ap(15) calibre(0))
)
(define "armor_entourage_wood"
	("armor_adjustable" thresh_fg(5) thresh_ap(3) dur_fg(8) dur_ap(15) calibre(0))
	("bullet_pass_bullet")
)
(define "armor_fence_concrete"
	("armor_medium_base" name(bullet_pass_rpg))
)
(define "armor_entourage_concrete"
	("armor_medium_base" name(bullet_pass_rpg))
)
(define "armor_fence_steel"
	("armor_medium_base" name(bullet_pass_rpg))
)
(define "armor_entourage_steel"
	("armor_medium_base" name(bullet_pass_rpg))
)

(define "armor_use_volume_thickness"
	{armor
		{setting "body"
			{ray_cast_thickness 0}
		}
		{setting "roof"
			{ray_cast_thickness 0}
		}
	}
)

(define "armor_disable_damage_acc"
	{armor
		{setting "body"
			{disable_damage_acc}
		}
		{setting "roof"
			{disable_damage_acc}
		}
	}
)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(include "texmod.inc")

("armor_medium" args(1.0))

;==============CW defines
;fixing CtA bug with stucking humans in windows
(define "building_attach_place"
	{boarder
		{link "%1" "attach%1"}
		{door "attach%1"}
	}
)
(define "building_attach"
	("building_attach_place" args(0))
	("building_attach_place" args(1))
	("building_attach_place" args(2))
	("building_attach_place" args(3))
	("building_attach_place" args(4))
	("building_attach_place" args(5))
	("building_attach_place" args(6))
	("building_attach_place" args(7))
	("building_attach_place" args(8))
	("building_attach_place" args(9))
	("building_attach_place" args(10))
	("building_attach_place" args(11))
	("building_attach_place" args(12))
	("building_attach_place" args(13))
	("building_attach_place" args(14))
	("building_attach_place" args(15))
	("building_attach_place" args(16))
	("building_attach_place" args(17))
	("building_attach_place" args(18))
	("building_attach_place" args(19))
	("building_attach_place" args(20))
)

;	{placer
;		{place "1" {attach  snipe_cover} 		{linkbone "attach1"}}
;		{place "2" {attach  snipe_cover} 		{linkbone "attach2"}}
;	}	
;	{boarder}
;	("building_attach_place" args(1))
;	("building_attach_place" args(2))