;====================================CtA=====================
(define "items_light"
	{item "5x39" "ammo" 50 {max 1000}}
	{item "5x45" "ammo" 50 {max 1000}}
	{item "7x39" "ammo" 50 {max 1000}}
	{item "7x51" "ammo" 50 {max 1000}}
	{item "7x51b" "ammo" 50 {max 1000}}
	{item "7x54" "ammo" 50 {max 1000}}
	{item "9x18" "ammo" 50 {max 1000}}
	{item "9x19" "ammo" 50 {max 1000}}
	{item "9x19b" "ammo" 50 {max 1000}}
	{item "9x39" "ammo" 50 {max 1000}}
	{item "11x23" "ammo" 50 {max 1000}{value 2}}
	{item "12gauge" "ammo" 50 {max 1000}{value 2}}
	{item "12x99" "ammo" 50 {max 1000}{value 2}}
	{item "12x108" "ammo" 50 {max 1000}{value 2}}
	{item "40x46" "ammo" 2 {max 20}{value 5}}
	{item "81mm_mortar" "fg" "ammo" 2 {max 120}{value 2}}
	{item "81mm_mortar" "sm" "ammo" 1 {max 5}{value 2}}
	{item "82mm_mortar" "fg" "ammo" 2 {max 120}{value 2}}
	{item "82mm_mortar" "sm" "ammo" 1 {max 5}{value 2}}
	{item "bandage" 1 {max 5}{value 1}}
)
(define "items_heavy"
	{item "bullet15" "ap" "ammo" 25 {max 400}{value 5}}
	{item "bullet25" "ap" "ammo" 25 {max 400}{value 5}}
	{item "bullet25" "fg" "ammo" 25 {max 200}{value 5}}
	{item "bullet30" "ap" "ammo" 25 {max 400}{value 5}}
	{item "bullet30" "fg" "ammo" 25 {max 200}{value 5}}
	{item "bullet100" "fg" "ammo" 1 {max 10}{value 5}}
	{item "bullet100" "atgm" "ammo" 1 {max 5}{value 25}}
	{item "bullet105" "ap" "ammo" 1 {max 20}{value 5}}
	{item "bullet105" "fg" "ammo" 1 {max 10}{value 5}}
	{item "bullet105" "heat" "ammo" 1 {max 5}{value 5}}
	{item "bullet115" "ap" "ammo" 1 {max 20}{value 5}}
	{item "bullet115" "fg" "ammo" 1 {max 10}{value 5}}
	{item "bullet115" "heat" "ammo" 1 {max 5}{value 5}}
	{item "bullet120" "ap" "ammo" 1 {max 20}{value 5}}
	{item "bullet120" "fg" "ammo" 1 {max 10}{value 5}}
	{item "bullet120" "heat" "ammo" 1 {max 5}{value 5}}
	{item "bullet125" "ap" "ammo" 1 {max 20}{value 5}}
	{item "bullet125" "fg" "ammo" 1 {max 10}{value 5}}
	{item "bullet125" "heat" "ammo" 1 {max 5}{value 5}}
	{item "bullet125" "atgm" "ammo" 1 {max 5}{value 25}}
	{item "bullet135" "atgm" "ammo" 1 {max 5}{value 25}}
	{item "bullet152" "atgm" "ammo" 1 {max 5}{value 25}}
	{item "spg9" "ap" "ammo" 1 {max 20}{value 5}}
	{item "spg9" "fg" "ammo" 1 {max 10}{value 5}}
	{item "grenade" "decoy"  1 {max 1}{value 5}}
)


(define "supply_ammo"
	{extender "supply_zone"
		{resupply
			("items_light")
		}
		{radius 			8}		;resupply radius in meter
		{resupplyPeriod 	5}		;resupply period in seconds
		{regenerationPeriod 20}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				100}	;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.25}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)
(define "flag_ammo"
	{extender "supply_zone"
		{resupply
			("items_light")
		}
		{radius 			5}		;resupply radius in meter
		{resupplyPeriod 	5}		;resupply period in seconds
		{regenerationPeriod 20}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				100}	;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.25}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)
(define "flag_ammo_heavy"
	{extender "supply_zone"
		{resupply
			("items_light")
			("items_heavy")
		}
		{radius 			15}		;resupply radius in meter
		{resupplyPeriod 	10}		;resupply period in seconds
		{regenerationPeriod 20}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				500}	;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.25}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)
(define "apc_ammo"
	{extender "supply_zone"
		{resupply
			("items_light")
			("items_heavy")		
		}
		{radius 			10}		;resupply radius in meter
		{resupplyPeriod 	2.5}	;resupply period in seconds
		{regenerationPeriod 25}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				250}	;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.25}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)
(define "truck_ammo"
	{extender "supply_zone"
		{resupply
			("items_light")	
		}
		{radius 			10}		;resupply radius in meter
		{resupplyPeriod 	2.5}	;resupply period in seconds
		{regenerationPeriod 25}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				500}	;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.25}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)
(define "truck_ammo_heavy"
	{extender "supply_zone"
		{resupply
			("items_light")
			("items_heavy")		
		}
		{radius 			10}		;resupply radius in meter
		{resupplyPeriod 	2.5}	;resupply period in seconds
		{regenerationPeriod 25}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				500}	;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.25}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)
;====================================mowas2=====================

(define "para_ammo"
	{extender "supply_zone"
		{resupply
			{item "rifle" "ammo" 25 {max 100}}
			{item "pistol" "ammo" 100 {max 400}}
			{item "mgun" "ammo" 100	{max 600}}
			{item "bandage"	1 {max 3}}
			{item "ptr" "ammo" 5 {max 10}}
			{item "bazooka" "ammo" 1 {max 3}}
			{item "panzershreck" "ammo" 1 {max 3}}
			{item "m18recoilless" "ammo" 1 {max 3}}
			{item "piatrocket" "ammo" 1	{max 3}}
			{item "type_4" "ammo" 1	{max 3}}
			{item "rifle_grenade" "ammo" 2 {max 5}}
			{item "rifle_grenade_at" "ammo" 2 {max 5}}
			{item "shotgun" "ammo" 3 {max 20}}
			{item "mortar" "fg" "ammo" 3 {max 30}{value 2}}
			{item "hmgun" "ammo" 30 {max 300}{value 2}}
		}
		{radius 			6}		;resupply radius in meter
		{resupplyPeriod 	5}		;resupply period in seconds
		{regenerationPeriod 0}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				75}		;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo"
	{extender "supply_zone"
		{resupply
			{item "rifle" "ammo" 25 {max 150}}
			{item "pistol" "ammo" 100 {max 600}}
			{item "mgun" "ammo" 100	{max 800}}
			{item "bandage"	1 {max 3}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 1 {max 5}}
			{item "panzershreck" "ammo" 1 {max 5}}
			{item "m18recoilless" "ammo" 1 {max 5}}
			{item "piatrocket" "ammo" 1 {max 5}}
			{item "type_4" "ammo" 1 {max 5}}
			{item "rifle_grenade" "ammo" 2 {max 10}}
			{item "rifle_grenade_at" "ammo" 2 {max 10}}
			{item "shotgun" "ammo" 5 {max 30}}
			{item "mortar" "fg" "ammo" 5 {max 30}{value 2}}
			{item "hmgun" "ammo" 50 {max 300}{value 2}}
		}
		{radius 			10}
		{resupplyPeriod 	5}
		{regenerationPeriod 30}
		{limit 				150}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo_art"
	{extender "supply_zone"
		{resupply
			{item "rifle" "ammo" 25 {max 150}}
			{item "pistol" "ammo" 100 {max 600}}
			{item "mgun" "ammo" 100	{max 800}}
			{item "bandage"	1 {max 3}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 1 {max 5}}
			{item "panzershreck" "ammo" 1 {max 5}}
			{item "m18recoilless" "ammo" 1 {max 5}}
			{item "piatrocket" "ammo" 1 {max 5}}
			{item "type_4" "ammo" 1 {max 5}}
			{item "rifle_grenade" "ammo" 2 {max 10}}
			{item "rifle_grenade_at" "ammo" 2 {max 10}}
			{item "shotgun" "ammo" 5 {max 30}}
			{item "mortar" "fg" "ammo" 5 {max 30}{value 2}}
			{item "hmgun" "ammo" 50 {max 300}{value 2}}
			{item "mortar150" "fg" "ammo" 2 {max 15}{value 2}}
			;
			{item "bullet20" "zenite" "ammo" 10 {max 100}{value 2}}
			{item "bullet25" "zenite" "ammo" 10 {max 100}{value 2}}
			{item "bullet37" "zenite" "ammo" 10 {max 100}{value 2}}
			{item "bullet40" "zenite" "ammo" 10 {max 100}{value 2}}
			{item "bullet37" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet37" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet40" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet40" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet45" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet45" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet47" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet47" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet50" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet50" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet57" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet57" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet75" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet75" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet76" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet76" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet77" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet77" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet85" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet85" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet88" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet88" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet89" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet89" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet90" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet90" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet93" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet93" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet95" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet95" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet100" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet100" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet105" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet120" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet122" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet128" "ap" "ammo" 2 {max 15}{value 2}}
			;
			{item "bullet105" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet120" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet122" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet128" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet150" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet152" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet155" "fg" "ammo" 1 {max 10}{value 5}}
			;
			{item "bullet203" "ammo" 1 {max 5}{value 5}}
			{item "bullet290" "ammo" 1 {max 5}{value 5}}
			;
			{item "calliope" "ammo" 5 {max 60}{value 5}}
			{item "lm_ammo" "ammo" 5 {max 32}{value 5}}
			{item "bm8" "ammo" 5 {max 24}{value 5}}
			{item "katusha" "ammo" 3 {max 16}{value 5}}
			{item "panzerwerfer42" "ammo" 2 {max 10}{value 5}}
			{item "nebel41" "ammo" 2 {max 12}{value 5}}
			{item "nebel42" "ammo" 2 {max 12}{value 5}}
			{item "20cm_rocket" "ammo" 2 {max 10}{value 5}}
			{item "tulip" "ammo" 2 {max 10}{value 5}}
			;
			{item "30cm_rocket" "ammo" 1 {max 5}{value 10}}
			{item "sturmtiger" "ammo" 1 {max 5}{value 10}}
		}
		{radius 			10}
		{resupplyPeriod 	5}
		{regenerationPeriod 30}
		{limit 				250}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)