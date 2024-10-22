(include "veterancy.inc")
(define "stealth_in_sp_only"
	(mod not "mp"
		{"stealth"}
	)
)
(define "training_civilian"
{"housewarrior" none}
{"houseassault" none}
{"suppressresistance" none}
{"firearmssuperiority" none}
{"dig" none}

)
(define "training_militia"
{"housewarrior" basic}
{"houseassault" basic}
{"suppressresistance" basic}
{"firearmssuperiority" basic}
{"dig" none}

)
(define "training_supporters"
{"housewarrior" advanced}
{"houseassault" basic}
{"suppressresistance" advanced}
{"firearmssuperiority" basic}
{"dig" basic}

)
(define "training_soldier"
{"housewarrior" advanced}
{"houseassault" advanced}
{"suppressresistance" advanced}
{"firearmssuperiority" advanced}
{"dig" basic}

)
(define "training_specialist"
{"housewarrior" expert}
{"houseassault" advanced}
{"suppressresistance" advanced}
{"firearmssuperiority" expert}
{"dig" none}

)
(define "training_assaultinf"
{"housewarrior" expert}
{"houseassault" expert}
{"suppressresistance" expert}
{"firearmssuperiority" expert}
{"dig" none}
{"minedetection" 10}

)
(define "training_elite"
{"housewarrior" master}
{"houseassault" master}
{"suppressresistance" master}
{"firearmssuperiority" master}
{"dig" none}
{"minedetection" 10}

{"spy"}
)
(define "vehicle_skills_civilian"
{"skill_tank" none}
{"skill_apc" none}
{"skill_car" none}
{"skill_stan" none}
{"skill_plane" none}

)
(define "vehicle_skills_soldier"
{"skill_tank" none}
{"skill_apc" none}
{"skill_car" basic}
{"skill_stan" basic}
{"skill_plane" none}

)
(define "vehicle_skills_elitesoldier"
{"skill_tank" none}
{"skill_apc" basic}
{"skill_car" basic}
{"skill_stan" advanced}
{"skill_plane" none}

)
(define "vehicle_skills_veh_supporter"
{"skill_tank" none}
{"skill_apc" basic}
{"skill_car" advanced}
{"skill_stan" advanced}
{"skill_plane" none}

)
(define "vehicle_skills_tankman"
{"skill_tank" advanced}
{"skill_apc" advanced}
{"skill_car" advanced}
{"skill_stan" basic}
{"skill_plane" none}

)
(define "vehicle_skills_pilot"
{"skill_tank" none}
{"skill_apc" basic}
{"skill_car" basic}
{"skill_stan" basic}
{"skill_plane" advanced}

)
(define "traits_civilian"
	{perks
		{"health" "100%"}
;		{"health_regeneration" "100%"}
		{"mgun" none}
		{"pistol" none}
		{"power" "100%"}
;		{"stamina_regeneration" "100%"}
		{"rifle" none}
		{"smg" none}
		{"melee" basic}
		{"spy"} 
        {"vision" human}
		
		
		("training_civilian")
		("vehicle_skills_civilian")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_engineering_troops"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" none}
		{"pistol" basic}
		{"gra_launch" basic}
		{"melee" basic}
		{"avoidance" basic}
		{"health" "150%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"minedetection" 15}
		
		
		("training_supporters")
		{"build"}
		("vehicle_skills_soldier")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_engineer"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" none}
		{"pistol" basic}
		{"gra_launch" basic}
		{"melee" basic}
		{"avoidance" basic}
		{"health" "150%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		;{fortification}
		;{mechanic}
		
		
		("training_supporters")
		{"repair"}
		{"build" basic}
		("vehicle_skills_soldier")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_vehicle_supporter"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" none}
		{"pistol" basic}
		{"gra_launch" basic}
		{"melee" basic}
		{"avoidance" basic}
		{"health" "150%"}
;		{"health_regeneration" "100%"}
		{"power" "100%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		;{fortification}
		;{mechanic "-repair_lev2" factor 0.33}
		
		
		("training_supporters")
		{"repair"}
		("vehicle_skills_veh_supporter")
	}
;	{veterancy ("veterancy_crew")}
)
(define "traits_pilot"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" none}
		{"rifle" basic}
		{"rocketlauncher" none}
		{"pistol" advanced}
		{"gra_launch" none}
		{"melee" basic}
		{"avoidance" expert}
		{"health" "150%"}
;		{"health_regeneration" "100%"}
		{"power" "110%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 1}		
		
		
		("training_supporters")
		{"repair"}
		("vehicle_skills_pilot")
		}
;	{veterancy ("veterancy_crew")}
)
(define "traits_tankman"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" basic}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" basic}
		{"pistol" advanced}
		{"gra_launch" none}
		{"melee" basic}
		{"avoidance" basic}
		{"health" "100%"}
;		{"health_regeneration" "100%"}

		{"power" "100%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		;{fortification}
		;{mechanic "-repair_lev3" factor 0.5}
		

		("training_supporters")
		{"repair"}
		("vehicle_skills_tankman")
	}
;	{veterancy ("veterancy_crew")}
)

(define "traits_tankman_wounded"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" basic}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" basic}
		{"pistol" advanced}
		{"gra_launch" none}
		{"melee" basic}
		{"avoidance" basic}
		{"health" "50%"}
;		{"health_regeneration" "100%"}

		{"power" "25%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		;{fortification}
		;{mechanic "-repair_lev3" factor 0.5}
		
		
		("training_supporters")
		{"repair"}
		("vehicle_skills_tankman")
	}
;	{veterancy ("veterancy_crew")}
)

(define "traits_heavy_sniper"
	{perks
		{"spy"} 
        {"vision" mp_sniper}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" expert}
		{"rocketlauncher" advanced}
		{"pistol" expert}
		{"gra_launch" basic}
		{"melee" advanced}
		{"avoidance" advanced}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"telescope"}
;		{"aimedshot"}
		{"field_glass"}
		{"stealth"}
		
		
		("vehicle_skills_soldier")
		("training_specialist")
		{"at_rifle" master}
 	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_officer"
	{perks
		{"spy"} 
        {"vision" mp_officer}
		{"smg" advanced}
		{"mgun" advanced}
		{"rifle" advanced}
		{"rocketlauncher" advanced}
		{"pistol" expert}
		{"gra_launch" advanced}
		{"melee" advanced}
		{"avoidance" advanced}
		{"health" "150%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"field_glass"}
;		{"medic" 10.0}
		{"spotter" basic}
		("vehicle_skills_elitesoldier")
		("training_specialist")

	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_scout"
	{perks
		{"spy"} 
        {"vision" mp_specnaz}
		{"smg" expert}
		{"mgun" expert}
		{"rifle" expert}
		{"rocketlauncher" expert}
		{"pistol" expert}
		{"gra_launch" expert}
		{"melee" master}
		{"avoidance" master}
		{"health" "180%"}
;		{"health_regeneration" "100%"}
		{"power" "300%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 1.1}
		{"telescope"}
;		{"aimedshot"}
		{"stealth"}
		{"field_glass"}
;		{"medic" 10.0}
		{"spotter" basic}
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_specnaz")}
)
;===========================================
(define "traits_militia_smg"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" none}
		{"mgun" none}
		{"rifle" none}
		{"rocketlauncher" none}
		{"pistol" basic}
		{"gra_launch" none}
		{"melee" basic}
		{"avoidance" none}
		{"health" "130%"}
;		{"health_regeneration" "100%"}
		{"power" "130%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		
		
		("vehicle_skills_civilian")
		("training_militia")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_militia_mgun"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" basic}
		{"mgun" basic}
		{"rifle" none}
		{"rocketlauncher" none}
		{"pistol" basic}
		{"gra_launch" basic}
		{"melee" basic}
		{"avoidance" none}
		{"health" "130%"}
;		{"health_regeneration" "100%"}
		{"power" "130%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		
		
		("vehicle_skills_civilian")
		("training_militia")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_militia_bazooker"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" basic}
		{"mgun" none}
		{"rifle" none}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" basic}
		{"melee" basic}
		{"avoidance" none}
		{"health" "130%"}
;		{"health_regeneration" "100%"}
		{"power" "130%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		
		
		("vehicle_skills_civilian")
		("training_militia")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_militia_sniper"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" none}
		{"mgun" none}
		{"rifle" basic}
		{"rocketlauncher" none}
		{"pistol" basic}
		{"gra_launch" none}
		{"melee" basic}
		{"avoidance" none}
		{"health" "130%"}
;		{"health_regeneration" "100%"}
		{"power" "130%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		{"telescope"}
;		{"aimedshot"}
		{"field_glass"}
		
		
		("vehicle_skills_civilian")
		("training_militia")
	}
;	{veterancy ("veterancy_1")}
)













;===========================================
(define "traits_army_smg"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" advanced}
		{"melee" advanced}
		{"avoidance" basic}
		{"health" "180%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		
		
		("vehicle_skills_soldier")
		("training_soldier")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_army_smg_wounded"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" advanced}
		{"melee" advanced}
		{"avoidance" basic}
		{"health" "75%"}
;		{"health_regeneration" "100%"}
		{"power" "25%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		
		
		("vehicle_skills_soldier")
		("training_soldier")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_army_bazooker"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" advanced}
		{"pistol" basic}
		{"gra_launch" basic}
		{"melee" advanced}
		{"avoidance" basic}
		{"health" "150%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		
		
		("vehicle_skills_soldier")
		("training_soldier")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_army_sniper"
	{perks
		{"spy"} 
        {"vision" mp_sniper}
		{"smg" basic}
		{"mgun" basic}
		{"rifle" advanced}
		{"rocketlauncher" basic}
		{"pistol" advanced}
		{"gra_launch" basic}
		{"melee" basic}
		{"avoidance" basic}
		{"health" "180%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		{"telescope"}
;		{"aimedshot"}
		{"field_glass"}
		
		
		("vehicle_skills_soldier")
		("training_soldier")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_army_mgun"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" advanced}
		{"melee" basic}
		{"avoidance" basic}
		{"health" "180%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		
		
		("vehicle_skills_soldier")
		("training_soldier")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_army_com"
	{perks
		{"spy"} 
        {"vision" mp_officer}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" basic}
		{"melee" advanced}
		{"avoidance" basic}
		{"health" "180%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		{"field_glass"}
;		{"medic" 10.0}
		{"spotter" "basic"}
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_army_spotter"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" basic}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" advanced}
		{"melee" advanced}
		{"avoidance" basic}
		{"health" "180%"}
;		{"health_regeneration" "100%"}
		{"power" "150%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.8}
		{"stealth"}
		{"telescope"}
;		{"aimedshot"}
		{"field_glass"}
		{"spotter" "basic"}
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
;===========================================
(define "traits_advanced_com"
	{perks
		{"spy"} 
        {"vision" mp_officer}
		{"smg" expert}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" basic}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "200%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"field_glass"}
;		{"medic" 10.0}
		{"spotter" "basic"}
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_advanced_mgun"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" expert}
		{"rifle" basic}
		{"rocketlauncher" expert}
		{"pistol" basic}
		{"gra_launch" advanced}
		{"melee" expert}
		{"avoidance" basic}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "200%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_advanced_bazooker"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" expert}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" basic}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "200%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_advanced_smg"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" expert}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" basic}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "200%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_advanced_medic"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" expert}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" basic}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "200%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
;		{"medic" 10.0}
		
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_advanced_sniper"
	{perks
		{"spy"} 
        {"vision" mp_sniper}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" expert}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" advanced}
		{"melee" expert}
		{"avoidance" advanced}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "200%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
;		{"stealth"}
		{"telescope"}
;		{"aimedshot"}
		{"field_glass"}
		
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
(define "traits_advanced_spotter"
	{perks
		{"spy"} 
        {"vision" mp_sniper}
		{"smg" expert}
		{"mgun" basic}
		{"rifle" advanced}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" advanced}
		{"health" "200%"}
;		{"health_regeneration" "100%"}
		{"power" "200%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"stealth"}
		{"telescope"}
;		{"aimedshot"}
		{"field_glass"}
		
		
		("vehicle_skills_soldier")
		("training_specialist")
	}
;	{veterancy ("veterancy_1")}
)
;===========================================
(define "traits_specnaz_smg"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" expert}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
;		{"medic" 10.0}
		
		
		("vehicle_skills_soldier")
		("training_assaultinf")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_specnaz_com"
	{perks
		{"spy"} 
        {"vision" mp_officer}
		{"smg" expert}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"field_glass"}
;		{"medic" 10.0}
		{"spotter" "basic"}
		
		("vehicle_skills_soldier")
		("training_assaultinf")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_specnaz_bazooker"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" advanced}
		{"rifle" basic}
		{"rocketlauncher" expert}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
;		{"medic" 10.0}
		
		
		("vehicle_skills_soldier")
		("training_assaultinf")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_specnaz_mgun"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" advanced}
		{"mgun" expert}
		{"rifle" basic}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" expert}
		{"melee" expert}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
;		{"medic" 10.0}
		
		
		("vehicle_skills_soldier")
		("training_assaultinf")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_specnaz_grenadier"
	{perks
		{"spy"} 
        {"vision" mp_soldier}
		{"smg" expert}
		{"mgun" basic}
		{"rifle" expert}
		{"rocketlauncher" basic}
		{"pistol" basic}
		{"gra_launch" expert}
		{"melee" advanced}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
;		{"medic" 10.0}
		
		
		("vehicle_skills_soldier")
		("training_assaultinf")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_specnaz_spotter"
	{perks
		{"spy"} 
        {"vision" mp_specnaz}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" advanced}
		{"rocketlauncher" advanced}
		{"pistol" advanced}
		{"gra_launch" basic}
		{"melee" advanced}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"telescope"}
;		{"aimedshot"}
		{"stealth"}
		{"field_glass"}
;		{"medic" 10.0}
		
		
		("vehicle_skills_soldier")
		("training_assaultinf")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_specnaz_sniper"
	{perks
		{"spy"} 
        {"vision" mp_sniper}
		{"smg" advanced}
		{"mgun" basic}
		{"rifle" expert}
		{"rocketlauncher" advanced}
		{"pistol" expert}
		{"gra_launch" basic}
		{"melee" advanced}
		{"avoidance" basic}
		{"health" "250%"}
		{"power" "180%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 0.9}
		{"telescope"}
;		{"aimedshot"}
;		{"stealth"}
		{"field_glass"}
;		{"medic" 10.0}
		
		
		("vehicle_skills_soldier")
		("training_assaultinf")
	}
;	{veterancy ("veterancy_specnaz")}
)

(define "traits_elite_smg"
	{perks
		{"spy"} 
        {"vision" mp_specnaz}
		{"smg" expert}
		{"mgun" expert}
		{"rifle" expert}
		{"rocketlauncher" expert}
		{"pistol" expert}
		{"gra_launch" expert}
		{"melee" master}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "250%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 1.1}
		("stealth_in_sp_only")
		{"field_glass"}
;		{"medic" 10.0}
		
		
		("vehicle_skills_elitesoldier")
		("training_elite")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_elite_mgun"
	{perks
		{"spy"} 
        {"vision" mp_specnaz}
		{"smg" expert}
		{"mgun" expert}
		{"rifle" expert}
		{"rocketlauncher" expert}
		{"pistol" expert}
		{"gra_launch" expert}
		{"melee" master}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "250%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 1.1}
		("stealth_in_sp_only")
		{"field_glass"}
;		{"medic" 10.0}
		
		
		("vehicle_skills_elitesoldier")
		("training_elite")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_elite_bazooker"
	{perks
		{"spy"} 
        {"vision" mp_specnaz}
		{"smg" expert}
		{"mgun" expert}
		{"rifle" expert}
		{"rocketlauncher" expert}
		{"pistol" expert}
		{"gra_launch" expert}
		{"melee" master}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "250%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 1.1}
		("stealth_in_sp_only")
		{"field_glass"}
;		{"medic" 10.0}
		
		
		("vehicle_skills_elitesoldier")
		("training_elite")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_elite_com"
	{perks
		{"spy"} 
        {"vision" mp_elite_officer}
		{"smg" expert}
		{"mgun" expert}
		{"rifle" expert}
		{"rocketlauncher" expert}
		{"pistol" expert}
		{"gra_launch" expert}
		{"melee" master}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "250%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 1.1}
		("stealth_in_sp_only")
		{"field_glass"}
;		{"medic" 10.0}
		{"spotter" "basic"}
		
		("vehicle_skills_elitesoldier")
		("training_elite")
	}
;	{veterancy ("veterancy_specnaz")}
)
(define "traits_elite_sniper"
	{perks
		{"spy"} 
        {"vision" mp_sniper}
		{"smg" expert}
		{"mgun" expert}
		{"rifle" expert}
		{"rocketlauncher" expert}
		{"pistol" expert}
		{"gra_launch" expert}
		{"melee" master}
		{"avoidance" advanced}
		{"health" "250%"}
		{"power" "250%"}
;		{"stamina_regeneration" "100%"}
		{"speed" 1.1}
		{"stealth"}
		{"telescope"}
;		{"aimedshot"}
		{"field_glass"}
;		{"medic" 10.0}
		
		
		("vehicle_skills_elitesoldier")
		("training_elite")
	}
;	{veterancy ("veterancy_specnaz")}
)
