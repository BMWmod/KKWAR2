(define "common_fg"
 		else stuff "fx_proj_pointer"
		else stuff "fx_bul_small"
		else stuff "fx_bul_med"
		else stuff "fx_10_15 fx_ap"
		else stuff "fx_10_15"		{spawn "ex_air_norm"}
		else stuff "fx_16_24 fx_ap"
		else stuff "fx_16_24"		{spawn "ex_air_norm"}
		else stuff "fx_25_40 fx_ap"
		else stuff "fx_25_40"		{spawn "ex_air_norm"}
		else stuff "fx_gren fx_ap"
		else stuff "fx_gren fx_cm"	{spawn "ex_air_big"}
		else stuff "fx_gren"		{spawn "ex_air_norm"}
		else stuff "fx_45_89 fx_ap"
		else stuff "fx_45_89 fx_cm"	{spawn "ex_air_cmnorm"}
		else stuff "fx_45_89"		{spawn "ex_air_norm2"}
		else stuff "fx_90_110 fx_ap"
		else stuff "fx_90_110 fx_cm"{spawn "ex_air_cmnorm"}
		else stuff "fx_90_110"		{spawn "ex_air_big"}
		else stuff "fx_111_145 fx_ap"
		else stuff "fx_111_145 fx_cm"{spawn "ex_air_cmbig"}
		else stuff "fx_111_145"		{spawn "ex_air_big2"}
		else stuff "fx_146_299 fx_ap"
		else stuff "fx_146_299 fx_cm"{spawn "ex_air_cmbig"}
		else stuff "fx_146_299"		 {spawn "ex_air_extrabig"}
		else stuff "fx_upto15kg fx_cm"{spawn "ex_air_cmbig"}
		else stuff "fx_upto15kg"	 {spawn "ex_air_extrabig"}
		else stuff "fx_upto50kg"	 {spawn "ex_air_extrabig"}
		else stuff "fx_upto250kg"	 {spawn "ex_air_extrabig"}
		else stuff "fx_upto1000kg"	 {spawn "ex_air_extrabig"}
		else stuff "molotov_coctail"	{spawn "ex_molot"}
		else stuff "big sm"			{spawn "ex_air_norm2"}
		else stuff "sm"				{spawn "ex_air_norm"}
		else stuff "fx_tos"			{spawn "ex_bomb_big_tos"}
		else stuff "fx_shmel"		{spawn "ex_shmel"}
)
(define "metal"
 		else stuff "fx_proj_pointer"
		else stuff "fx_bul_small"	{spawn "metal_hit_bul"}
		else stuff "fx_bul_med"		{spawn "metal_hit_bul"}
		else stuff "fx_10_15 fx_ap"	{spawn "metal_hit_bul"}
		else stuff "fx_10_15"		{spawn "ex_air_norm"}
		else stuff "fx_16_24 fx_ap"	{spawn "metal_hit_br_small"}
		else stuff "fx_16_24"		{spawn "ex_air_norm"}
		else stuff "fx_25_40 fx_ap"	{spawn "metal_hit_br_small"}
		else stuff "fx_25_40"		{spawn "ex_air_norm"}
		else stuff "fx_gren fx_ap"	{spawn "metal_hit_br"}
		else stuff "fx_gren fx_cm"	{spawn "ex_air_big"}
		else stuff "fx_gren"		{spawn "ex_air_norm"}
		else stuff "fx_45_89 fx_ap"	{spawn "metal_hit_br"}
		else stuff "fx_45_89 fx_cm"	{spawn "metal_hit_fg"}
		else stuff "fx_45_89"		{spawn "metal_hit_fg"}
		else stuff "fx_90_110 fx_ap"{spawn "metal_hit_br"}
		else stuff "fx_90_110 fx_cm"{spawn "metal_hit_fg"}
		else stuff "fx_90_110"		{spawn "metal_hit_fg"}
		else stuff "fx_111_145 fx_ap"{spawn "metal_hit_br"}
		else stuff "fx_111_145 fx_cm"{spawn "metal_hit_fg"}
		else stuff "fx_111_145"		{spawn "metal_hit_fg_big"}
		else stuff "fx_146_299 fx_ap"{spawn "metal_hit_br"}
		else stuff "fx_146_299 fx_cm"{spawn "metal_hit_fg_big"}
		else stuff "fx_146_299"		 {spawn "metal_hit_fg_big"}
		else stuff "fx_upto15kg fx_cm"{spawn "metal_hit_fg_big"}
		else stuff "fx_upto15kg"	 {spawn "ex_air_extrabig"}
		else stuff "fx_upto50kg"	 {spawn "ex_air_extrabig"}
		else stuff "fx_upto250kg"	 {spawn "ex_air_extrabig"}
		else stuff "fx_upto1000kg"	 {spawn "ex_air_extrabig"}
		else stuff "molotov_coctail" {spawn "ex_molot"}
		else stuff "big sm"			
		else stuff "sm"				
		else stuff "fx_tos"			{spawn "ex_air_big2"}
		else stuff "fx_shmel"		{spawn "ex_air_big2"}
)




(define "hit_fx_flesh"
	{start_sound "human/hit" user_control}
	{if stuff "zenite"
		;{spawn "ex_air_norm"}
	else stuff "laser_ammo"
	else stuff "radar_ammo"
	else stuff "IR_ff_ammo"
	("common_fg")
	}
)

(define "hit_fx_steel"
	{if stuff "rus_radar_beam ammo"
		{tags add "rus_target_radar"}
		{delay 0.7
			{tags remove "rus_target_radar"}
		}
	else stuff "usa_radar_beam ammo"
		{tags add "usa_target_radar"}
		{delay 0.7
			{tags remove "usa_target_radar"}
		}
	else component "kaz1"
	else stuff "proj_pointer"
	("metal")
	}
)

(define "hit_fx_wood"
	{if stuff "proj_pointer"
	("common_fg")
	}
	{if stuff "proj_pointer"
	else stuff "bullet"
		{spawn "wood_hit_bul"}
	else stuff "mortar"
		{spawn "wood_hit_fg"}
	else stuff "zenite"
		{spawn "wood_hit_bul"}
	else stuff "shell small"
		{spawn "wood_hit_br_small"}
	else stuff "shell fg"
		{spawn "ex_mort_big"}
	else stuff "big shell fg bomb grad" ;Град
		{spawn "ex_bomb_big_wood_grad"}
	else stuff "shell"
		{spawn "wood_hit_br"}
	}
)

(define "hit_fx_concrete"
	{if stuff "proj_pointer"
	("common_fg")
	}
	{if stuff "proj_pointer"
	else stuff "bullet"
		{spawn "stone_hit_bul"}
		{spawn "ex_air_sm"}
	else stuff "zenite"
		{spawn "stone_hit_bul"}
		{spawn "ex_air_sm"}
	else stuff "big shell fg"
		{spawn	"stone_hit_br_big"}
	else stuff "shell small"
		{spawn	"stone_hit_br_small"}
	else stuff "laser_ammo"
	else stuff "radar_ammo"
	else stuff "IR_ff_ammo"
	else
		{spawn	"stone_hit_br"}
	}
)
(define "hit_fx_sand"
	{if stuff "proj_pointer"
	("common_fg")
	}
	{if stuff "proj_pointer"
	else stuff "zenite"
		{spawn "ex_air_sm"}
		{spawn "sand_hit_bul"}
	else stuff "mortar"
		{spawn "ex_mort_sm"}
	else stuff "shell fg"
		{spawn "ex_mort_big"}
	else stuff "bazooka"
		{spawn "ex_air_big"}
	else stuff "laser_ammo"
	else stuff "radar_ammo"
	else stuff "IR_ff_ammo"
	else
		{spawn "sand_hit_small"}
	}
)
(define "hit_fx_ice"
	{if stuff "proj_pointer"
	("common_fg")
	}
	{if stuff "proj_pointer"
	else stuff "shell fg"
		{spawn "ex_mort_sm_snow"}
	else stuff "laser_ammo"
	else stuff "radar_ammo"
	else stuff "IR_ff_ammo"
	else
		{spawn "snow_hit_small"}
	}
)
	; When a bullet hits, the scripts are called in the following sequence:
	; 1. bullet_hit
	;	- have no specified hit info;
	;	- detonate must be called there, because it can interrupt other hit processing;
	;	- called once per entity;
	; 2. bullet_hit_info 
	;	- conditions available: bullet_ricochet, bullet_pass, bullet_stuck, bullet_detonate, *bullet_pierce, *bullet_damage, *bullet_wreak, *obstacle_hit;
	;	- prefer to use it for visualization information;
	;	- called once per entity
	; 3. bullet_pierce
	;	- called for each pierced volume
	; 4. bullet_reflect or bullet_stuck
	;	- called once per entity if not pierced, destroyed or weaked
	; * bullet_wreak - checking that there was a weakening of the armor
	; * bullet_pierce - pierce only
	; * bullet_damage - pierce and damage
	; * obstacle_hit - not a player pointed or manual control target; can be combained with bullet_* conditions;

{"generic"
	{on bullet_hit
	   {if not material "dummy" 
	    {if stuff "fg_air"
		 {bullet_detonate}
	    }
	   }
	}
	{on bullet_hit_info
		{if not under_water
				{if material "flesh"
					("hit_fx_flesh")
				else material "steel"
					("hit_fx_steel")
				else material "steelball"
					{spawn "metal_hit_bul"}
				else material "wood"
					("hit_fx_wood")
				else material "concrete"
					("hit_fx_concrete")
				else material "sand"
					("hit_fx_sand")
				else material "ice"
					("hit_fx_ice")
				}
			{if material "flesh"
			    {if stuff "fx_proj_pointer"
				else {start_sound "human/hit" user_control} }
			}
			{if material "steel"
			    {if stuff "fx_proj_pointer"
				else stuff "bullet"
	                {start_sound "hit/small/metal" user_control}
			    else
			        {if stuff "shell ap" or stuff "shell apcr" or stuff "ptr" or stuff "bzt"
				        {if not stuff "gr_ic"
			                {if bullet_pierce
			                   {start_sound "hit/big/metal_penetration" user_control}
			  	            else bullet_damage
			                   {start_sound "hit/big/metal_penetration" user_control}
			                else bullet_ricochet
			                   {start_sound "hit/big/metal_recochet" user_control}
			                else
			                   {start_sound "hit/big/metal_hit" user_control}
			                }
						}
		 	        }
			    }
			}
		}
	}
}
(define "blast"
	("spawn")
)