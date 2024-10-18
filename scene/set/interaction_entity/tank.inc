;COLD WAR
{"tank"
(include "flamer.inc")
;   {friction 1}
;   {restitution 0.3}
	(include "tank_general_scripts_defines.inc")
;///////////////DPS system 2 by Pheonix/////////////////////////////////////////
(define "DPS_Effect"	
	{if rand %dps_apcr ; Поражение ПК снарядом
;               {components "d_a" break}
("cut_d_a_part" args "d_a1")("cut_d_a_part" args "d_a2")("cut_d_a_part" args "d_a3")("cut_d_a_part" args "d_a4")("cut_d_a_part" args "d_a5")
("cut_d_a_part" args "d_a6")("cut_d_a_part" args "d_a7")("cut_d_a_part" args "d_a8")("cut_d_a_part" args "d_a9")("cut_d_a_part" args "d_a10")
("cut_d_a_part" args "d_a11")("cut_d_a_part" args "d_a12")("cut_d_a_part" args "d_a13")("cut_d_a_part" args "d_a14")("cut_d_a_part" args "d_a15")
("cut_d_a_part" args "d_a16")("cut_d_a_part" args "d_a17")("cut_d_a_part" args "d_a18")("cut_d_a_part" args "d_a19")("cut_d_a_part" args "d_a20")
("cut_d_a_part" args "d_a21")("cut_d_a_part" args "d_a22")("cut_d_a_part" args "d_a23")("cut_d_a_part" args "d_a24")("cut_d_a_part" args "d_a25")
("cut_d_a_part" args "d_a26")("cut_d_a_part" args "d_a27")("cut_d_a_part" args "d_a28")("cut_d_a_part" args "d_a29")("cut_d_a_part" args "d_a30")
("cut_d_a_part" args "d_a31")("cut_d_a_part" args "d_a32")("cut_d_a_part" args "d_a33")("cut_d_a_part" args "d_a34")("cut_d_a_part" args "d_a35")
("cut_d_a_part" args "d_a36")("cut_d_a_part" args "d_a37")("cut_d_a_part" args "d_a38")("cut_d_a_part" args "d_a39")("cut_d_a_part" args "d_a40")
("cut_d_a_part" args "d_a41")("cut_d_a_part" args "d_a42")("cut_d_a_part" args "d_a43")("cut_d_a_part" args "d_a44")("cut_d_a_part" args "d_a45")
("cut_d_a_part" args "d_a46")("cut_d_a_part" args "d_a47")("cut_d_a_part" args "d_a48")("cut_d_a_part" args "d_a49")("cut_d_a_part" args "d_a50")
("cut_d_a_part" args "d_a51")("cut_d_a_part" args "d_a52")("cut_d_a_part" args "d_a53")("cut_d_a_part" args "d_a54")("cut_d_a_part" args "d_a55")
("cut_d_a_part" args "d_a56")("cut_d_a_part" args "d_a57")("cut_d_a_part" args "d_a58")("cut_d_a_part" args "d_a59")("cut_d_a_part" args "d_a60")
("cut_d_a_part" args "d_a61")("cut_d_a_part" args "d_a62")("cut_d_a_part" args "d_a63")("cut_d_a_part" args "d_a64")("cut_d_a_part" args "d_a65")
("cut_d_a_part" args "d_a66")("cut_d_a_part" args "d_a67")("cut_d_a_part" args "d_a68")("cut_d_a_part" args "d_a69")("cut_d_a_part" args "d_a70")
("cut_d_a_part" args "d_a71")("cut_d_a_part" args "d_a72")("cut_d_a_part" args "d_a73")("cut_d_a_part" args "d_a74")("cut_d_a_part" args "d_a75")
("cut_d_a_part" args "d_a76")("cut_d_a_part" args "d_a77")("cut_d_a_part" args "d_a78")("cut_d_a_part" args "d_a79")("cut_d_a_part" args "d_a80")
("cut_d_a_part" args "d_a81")("cut_d_a_part" args "d_a82")("cut_d_a_part" args "d_a83")("cut_d_a_part" args "d_a84")("cut_d_a_part" args "d_a85")
("cut_d_a_part" args "d_a86")("cut_d_a_part" args "d_a87")("cut_d_a_part" args "d_a88")("cut_d_a_part" args "d_a89")("cut_d_a_part" args "d_a90")
("cut_d_a_part" args "d_a91")("cut_d_a_part" args "d_a92")("cut_d_a_part" args "d_a93")("cut_d_a_part" args "d_a94")("cut_d_a_part" args "d_a95")
("cut_d_a_part" args "d_a96")("cut_d_a_part" args "d_a97")("cut_d_a_part" args "d_a98")("cut_d_a_part" args "d_a99")("cut_d_a_part" args "d_a100")
("cut_d_a_part" args "d_a101")("cut_d_a_part" args "d_a102")("cut_d_a_part" args "d_a103")("cut_d_a_part" args "d_a104")("cut_d_a_part" args "d_a105")
("cut_d_a_part" args "d_a106")("cut_d_a_part" args "d_a107")("cut_d_a_part" args "d_a108")("cut_d_a_part" args "d_a109")("cut_d_a_part" args "d_a110")
("cut_d_a_part" args "d_a111")("cut_d_a_part" args "d_a112")("cut_d_a_part" args "d_a113")("cut_d_a_part" args "d_a114")("cut_d_a_part" args "d_a115")
("cut_d_a_part" args "d_a116")("cut_d_a_part" args "d_a117")("cut_d_a_part" args "d_a118")("cut_d_a_part" args "d_a119")("cut_d_a_part" args "d_a120")
("cut_d_a_part" args "d_a121")("cut_d_a_part" args "d_a122")("cut_d_a_part" args "d_a123")("cut_d_a_part" args "d_a124")("cut_d_a_part" args "d_a125")
("cut_d_a_part" args "d_a126")("cut_d_a_part" args "d_a127")("cut_d_a_part" args "d_a128")("cut_d_a_part" args "d_a129")("cut_d_a_part" args "d_a130")
		   {damage_report "body" "era_pierced"}
;-----------------------------------------------------------------------------		
	else rand %dps_cm               ;Кум снаряд,ракета 
;                {components "d_a" break}
("blast_d_a" args d_a1)("blast_d_a" args d_a2)("blast_d_a" args d_a3)("blast_d_a" args d_a4)("blast_d_a" args d_a5)
("blast_d_a" args d_a6)("blast_d_a" args d_a7)("blast_d_a" args d_a8)("blast_d_a" args d_a9)("blast_d_a" args d_a10)
("blast_d_a" args d_a11)("blast_d_a" args d_a12)("blast_d_a" args d_a13)("blast_d_a" args d_a14)("blast_d_a" args d_a15)
("blast_d_a" args d_a16)("blast_d_a" args d_a17)("blast_d_a" args d_a18)("blast_d_a" args d_a19)("blast_d_a" args d_a20)
("blast_d_a" args d_a21)("blast_d_a" args d_a22)("blast_d_a" args d_a23)("blast_d_a" args d_a24)("blast_d_a" args d_a25)
("blast_d_a" args d_a26)("blast_d_a" args d_a27)("blast_d_a" args d_a28)("blast_d_a" args d_a29)("blast_d_a" args d_a30)
("blast_d_a" args d_a31)("blast_d_a" args d_a32)("blast_d_a" args d_a33)("blast_d_a" args d_a34)("blast_d_a" args d_a35)
("blast_d_a" args d_a36)("blast_d_a" args d_a37)("blast_d_a" args d_a38)("blast_d_a" args d_a39)("blast_d_a" args d_a40)
("blast_d_a" args d_a41)("blast_d_a" args d_a42)("blast_d_a" args d_a43)("blast_d_a" args d_a44)("blast_d_a" args d_a45)
("blast_d_a" args d_a46)("blast_d_a" args d_a47)("blast_d_a" args d_a48)("blast_d_a" args d_a49)("blast_d_a" args d_a50)
("blast_d_a" args d_a51)("blast_d_a" args d_a52)("blast_d_a" args d_a53)("blast_d_a" args d_a54)("blast_d_a" args d_a55)
("blast_d_a" args d_a56)("blast_d_a" args d_a57)("blast_d_a" args d_a58)("blast_d_a" args d_a59)("blast_d_a" args d_a60)
("blast_d_a" args d_a61)("blast_d_a" args d_a62)("blast_d_a" args d_a63)("blast_d_a" args d_a64)("blast_d_a" args d_a65)
("blast_d_a" args d_a66)("blast_d_a" args d_a67)("blast_d_a" args d_a68)("blast_d_a" args d_a69)("blast_d_a" args d_a70)
("blast_d_a" args d_a71)("blast_d_a" args d_a72)("blast_d_a" args d_a73)("blast_d_a" args d_a74)("blast_d_a" args d_a75)
("blast_d_a" args d_a76)("blast_d_a" args d_a77)("blast_d_a" args d_a78)("blast_d_a" args d_a79)("blast_d_a" args d_a80)
("blast_d_a" args d_a81)("blast_d_a" args d_a82)("blast_d_a" args d_a83)("blast_d_a" args d_a84)("blast_d_a" args d_a85)
("blast_d_a" args d_a86)("blast_d_a" args d_a87)("blast_d_a" args d_a88)("blast_d_a" args d_a89)("blast_d_a" args d_a90)
("blast_d_a" args d_a91)("blast_d_a" args d_a92)("blast_d_a" args d_a93)("blast_d_a" args d_a94)("blast_d_a" args d_a95)
("blast_d_a" args d_a96)("blast_d_a" args d_a97)("blast_d_a" args d_a98)("blast_d_a" args d_a99)("blast_d_a" args d_a100)
("blast_d_a" args d_a101)("blast_d_a" args d_a102)("blast_d_a" args d_a103)("blast_d_a" args d_a104)("blast_d_a" args d_a105)
("blast_d_a" args d_a106)("blast_d_a" args d_a107)("blast_d_a" args d_a108)("blast_d_a" args d_a109)("blast_d_a" args d_a110)
("blast_d_a" args d_a111)("blast_d_a" args d_a112)("blast_d_a" args d_a113)("blast_d_a" args d_a114)("blast_d_a" args d_a115)
("blast_d_a" args d_a116)("blast_d_a" args d_a117)("blast_d_a" args d_a118)("blast_d_a" args d_a119)("blast_d_a" args d_a120)
("blast_d_a" args d_a121)("blast_d_a" args d_a122)("blast_d_a" args d_a123)("blast_d_a" args d_a124)("blast_d_a" args d_a125)
("blast_d_a" args d_a126)("blast_d_a" args d_a127)("blast_d_a" args d_a128)("blast_d_a" args d_a129)("blast_d_a" args d_a130)
		{damage_report "body" "era_pierced"}
	else rand %dps_ap                ;ББ и прочее
	}
	                                     

)
;///////////////////////////////////END oF DPS 2///////////////////////////////////////////

;MEGA BUILDING BEGIN
=============================================================================================================================================================================
    (define "damage_process_pierce" ;by Svoyak  ;define's call's see in tank-armoredcar.inc, tank-light.inc, tank-medium.inc & tank-heavy.inc.
;=========Not applicable for CW tanks
;=================================
                {if stuff "%staff"
                    ("gun_hit" rand(%pierce_gun))
                    ("track_hit" max_rand(%pierce_front_back_track) min_rand(%pierce_left_right_track))
                                {if volume "body"
                                        {burn fx "smoke_dead_tank2" fake}
                                        {if rand %pierce_body__kill_charger {kill_crew "charger"}}
                                        {if rand %pierce_body__kill_driver {kill_crew "driver"}}
                                        {if rand %pierce_body__kill_gunner {kill_crew "gunner"}}
                                        {if rand %pierce_body__kill_commander {kill_crew "commander"}}
                                        {if rand %pierce_body__kill_gunner2 {kill_crew "gunner2"}}

                                    {if not tagged "destroyed"
                                        {if rand %pierce_body__burn {delay 3 2 {call "_burn"}}}
                                        {if rand %pierce_body__body_destroy {call "mp_destroy"}
                                        else rand %pierce_body__body_brake
                                                {if work "body" {components "body" break} {damage_report "body" "body_break"}}
                                        else operatable {damage_report "body" "shock"}
                                        else {damage_report "body" "body_pierced"}
                                        }
                    ;================Симуляция контузии
                                        {if operatable
                                            {if work "mover" {chassis_work 0} {tags add "stopped"}}
                                            {if work "turret" {ik_enable "turret" 0} {tags add "turr_jummed"}}
                                            {weapon_work "gun" 0}{weapon_work "gun1" 0}{weapon_work "gun2" 0}{weapon_work "gun3" 0}
			  {weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
                                            {delay %crew_shock_time
                                                {call "update_weaponry"}
                                                {if tagged "stopped"
                                                    {tags remove "stopped"}
                                                    {call "update_moveability"}
                                                }
                                                {if tagged "turr_jummed"
                                                    {if tagged "turret_brake"
                                                        {tags remove "turr_jummed"}
                                                    else tagged "turret_stopped_by_body"
                                                        {tags remove "turr_jummed"}
                                                    else
                                                        {tags remove "turr_jummed"}
                                                        {ik_enable "turret" 1}
                                                    }
                                                }
                                            }
                                        }
                                 }
                              
                                else volume "turret"
                                        {burn fx "smoke_dead_tank2" fake}
		            {if rand %pierce_turret__burn {delay 3 2 {call "_burn"}}
		            else rand %pierce_turret__explosive {delay 0.1 {call "explosion"}}
		            }
                                    {if hit_side front
                                       {if rand %pierce_turret_front__gun_brake
                                            {if work "gun" {components "gun" break} {damage_report "gun" "gun_broken"}}
                                        }
                                        {if rand %pierce_turret_front__turret_brake {components "turret" break} {ik_enable "turret" 0}}
                                    else hit_side back
                                        {if rand %pierce_turret_back__gun_brake
                                            {if work "gun" {components "gun" break} {damage_report "gun" "gun_broken"}}
		            }
		            {if rand %pierce_turret_back__turret_brake {components "turret" break} {ik_enable "turret" 0}}
		            else
                                        {if rand %pierce_turret_left_right__gun_brake
                                            {if work "gun" {components "gun" break} {damage_report "gun" "gun_broken"}}
		            }
		            {if rand %pierce_turret_left_right__turret_brake {components "turret" break} {ik_enable "turret" 0}}
                                    }
                                    {if rand %pierce_turret__kill_charger {kill_crew "charger"}}
                                    {if rand %pierce_turret__kill_driver {kill_crew "driver"}}
                                    {if rand %pierce_turret__kill_gunner {kill_crew "gunner"}}
                                    {if rand %pierce_turret__kill_commander {kill_crew "commander"}}
                                    {if rand %pierce_turret__kill_gunner2 {kill_crew "gunner2"}}

                                    ;==============Симуляция контузии
                                    {if operatable
                                                {ik_enable "turret" 0}
                                                {weapon_work "gun" 0} {weapon_work "gun1" 0}{weapon_work "gun2" 0} {weapon_work "gun3" 0}
			      {weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
                                                {tags add "turr_jummed"}
                                                {delay %crew_shock_time
                                                    {call "update_weaponry"}
                                                    {if tagged "turr_jummed"
                                                            {if tagged "turret_brake"
                                                                {tags remove "turr_jummed"}
                                                            else tagged "turret_stopped_by_body"
                                                                {tags remove "turr_jummed"}
                                                            else
                                                                {tags remove "turr_jummed"}
                                                                {ik_enable "turret" 1}
                                                            }
                                                    }
                                                }
                                    }
                                else volume "mantlet" 
		            {burn fx "smoke_dead_tank2" fake}
                                        {if rand %pierce_mantlet__gun_brake
                                            {if work "gun" {components "gun" break} {damage_report "gun" "gun_broken"}}
		            }
                                        {if rand %pierce_turret_front__turret_brake {components "turret" break}}
                                else volume "explosive"
                                    {if rand (* %pierce_inventory__explosive 0.2) {call "explosion"}}
                                else volume "engine"
                                        {burn fx "smoke_dead_tank2" fake}
		            {if rand %pierce_engine__engine_brake
			{if work "engine" {components "engine" break}}
			{if rand %pierce_engine__engine_burn {delay 3 2 {call "_burn"}}}
		            }
                                }
                };stuff
    )

    (define "damage_process_bullet_hit" ;by Svoyak
;====================================
                    {if stuff "%staff"
		{impulse dir %imp}
		{if rand %hit_body__engine_burn	{delay 2 2 {call "_burn"}}}
		{if volume "body"
                                {if rand %hit_body__explosive {call "explosion"}}
                                {if rand %hit_body__body_destroy {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
									
                                    (mod not "mp"
                                        {damage_report "body" "body_break"}
                                    )
                                }
                            
                        else volume "engine"
                                {if rand %hit_body__explosive {call "explosion"}}
                                {if rand %hit_engine__engine_brake
                                    {if work "engine" {components "engine" break}}
                                }
                                {if rand %hit_body__body_brake
                                    {components "body" break}
                                    (mod not "mp" {damage_report "body" "body_break"})
                                }
                        else volume "turret"
                                {if rand %hit_turret__explosive {call "explosion"} }
                                {if hit_side front
                                    {if rand %hit_turret_front__gun_brake
                                        {if work "gun" {components "gun" break} {damage_report "gun" "gun_broken"}}
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        else volume "mantlet"
                                {if rand %hit_turret__explosive {call "explosion"} }
                                {if rand %hit_turret_front__gun_brake
                                    {if work "gun"
                                        {components "gun" break}
		            {damage_report "gun" "gun_broken"}
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        }
                    }; stuff
;=====================================
    )

    (define "blast_damage_contusion" ;by Svoyak
	   {if not stuff "proj_pointer"
        {if volume "trackleft"            ;do nothing
        else volume "trackright"            ;do nothing
        else volume "roller"            ;do nothing
        else volume "wheel_work"            ;do nothing
        else volume "wheel"            ;do nothing
        else
            {if operatable
                {if not flag "already_blasted"
                    {if min_energy %blast_energy
                        {if rand %blast_rand_contusion
							{set "already_blasted" 1}
							{delay 0.5 {set "already_blasted" 0}}
                            {damage_report "body" "shock"}
                            {tags add "contusion"}
;                            {chassis_work 0}
                            {ik_enable "turret" 0}
                            {weapon_work "gun" 0}{weapon_work "gun1" 0}{weapon_work "gun2" 0}{weapon_work "gun3" 0}
		{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
							{icon_event "contusion" %blast_crew_shock_time}
                            {delay %blast_crew_shock_time "crew_shock"
								 {tags remove "contusion"}
                                 {call "update_moveability"}
								 {call "update_power"}
                            }
                        }
					}
                }
            }
			{if not flag "already_blasted"
				{if min_energy 13		;152mm but not 125mm
					;{if rand 0.5
						{set "already_blasted" 1}
						{delay 0.5 {set "already_blasted" 0}}
						{tags add "temp_no_power"}
						{call "update_power"}
						{delay 20
							 {tags remove "temp_no_power"}
							 {call "update_power"}
						}
					;}
				}
			}
        }
	  }
    )
	(define "pierce_damage_contusion"	;by Timosh
	  {if not stuff "proj_pointer"
	   {if operatable
		    {if tagged "pierce_damage_contusion_1"
			    {delay 0.5 
					{chassis_work 0}
						{if tagged "crit_system_destroyed" 
							{if rand 0.65 {crew_emit}}
						else tagged "crit_system_destroyed2" 
							{if rand 0.85 {crew_emit}}
						else tagged "crit_system_destroyed3"
							{if rand 0.95 {crew_emit}}
						}
				}
                else		
				{delay 0.6 {tags add "pierce_damage_contusion_1"}}
				{delay 60 {tags remove "pierce_damage_contusion_1"}}	
			}	
			{if not flag "already_blasted"
				{if rand %blast_rand_contusion
					{set "already_blasted" 1}
					{delay 0.5 {set "already_blasted" 0}}
					{damage_report "body" "shock"}
					{tags add "contusion"}
					{ik_enable "turret" 0}
					{weapon_work "gun" 0}{weapon_work "gun1" 0}{weapon_work "gun2" 0}{weapon_work "gun3" 0}
					{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
					{icon_event "contusion" %blast_crew_shock_time}
					{delay %blast_crew_shock_time "crew_shock"
						 {tags remove "contusion"}
						 {call "update_moveability"}
						 {call "update_power"}
					}
				}
			}
		}
	  }
	)
;MEGA BUILDING END ================================

;===============
;Anti-fire system 1.1 by Timosh
(define "anti_fire"
	{if not tagged "burned"
		{if not able "exploded"
			{damage_report "engine" "burn_engine"}
			{add_view "smoke_dead_norm" "burn_fire" "FXfire1"}
			{view start "burn_fire"}
			{add_view "smoke_black" "burn_fire" "FXfire1"}
			{play_sound "flame" 1}
			{view start "burn_fire"}
			{set "burn_fire" 1}
			{components "fire_indicator" break}
			{icon_event "burning" 12.0}
			 {if tagged "antifire_not_work"
			  ;{if rand %burn_prob  ;вероятность сгорания
	 			{explosive 1}
				{if not tagged "body_break"
					{if not flag "broken"	{set "broken" 1}	{stat_notify break}	}
				}	
				{tags add "burned"}
				{burn time 12}
				{delay 4 2  {call "check_burn_emit"}}
				{delay 10 2 {call "mp_destroy"} {start_sound "crush/medium/metal"} }
				{delay 10 2
					{components "engine" break}
					{start_sound "crush/medium/metal"}
              	      			{delay 5 4 {call "mp_destroy"} }
				}
				{delay 12
					{explosive 0}
					{set "burn_fire" 0}
					{components "fire_indicator" repair}
					{call "check_burn_emit"}
					{set "burning" 0}
					{if rand %expos_prob
						{view stop "burn_fire"}
						{stop_sound "flame"}
						{call "explosion"}
					else rand %fastburn_or_exp_prob
						{delay 10 2 {view stop "burn_fire"}}
						{call "burnout"}
					else
						{view stop "burn_fire"}
						{stop_sound "flame"}
						{able "burning" 0}
					}
				}
			else
				{icon_event "burning" 12.0}
				{delay 9 2
					{if rand 0.15 {components "engine" break}}
				}
				{delay 12
					{damage_report "engine" "antifire"}
					{view stop "burn_fire"}
					{stop_sound "flame"}
					{set "burn_fire" 0}
					{set "burning" 0}
					{components "fire_indicator" repair}
				}
				
			 ;}
			}
			{delay 12 {tags add "antifire_not_work"}}
		}
	}
)
	{on "burn_stage2" overload}
	{on "burn_stage3"
		{burn volume fx "smoke_dead_small" time 20 5 fake even_law}
		{log "burn_engine"}				
		{call "_burn"}
	}
;End of anti-fire system
;===============

;=============================================
;for biatlon

{on "chassis_turn_off" {chassis_work 0}}
{on "chassis_turn_on" {chassis_work 1}}
{on "weapon_turn_off" 	{weapon_work "gun" 0}{weapon_work "gun1" 0}{weapon_work "gun2" 0}{weapon_work "gun3" 0}
	{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}{weapon_work "mgun4" 0}
	{weapon_work "mgun5" 0}{weapon_work "mgun6" 0}{weapon_work "mgun20" 0}{weapon_work "mgun21" 0}
}
{on "weapon_turn_on" 	{weapon_work "gun" 1}{weapon_work "gun1" 1}{weapon_work "gun2" 1}{weapon_work "gun3" 1}
	{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}{weapon_work "mgun4" 1}
	{weapon_work "mgun5" 1}{weapon_work "mgun6" 1}{weapon_work "mgun20" 1}{weapon_work "mgun21" 1}
}
{on "biatlon_red_id" {add_view "tank_red_id"	"tank_id"	"basis"} {view start "tank_id"} {view show "tank_id"}}
{on "biatlon_blue_id" {add_view "tank_blue_id"	"tank_id"	"basis"} {view start "tank_id"} {view show "tank_id"}}
{on "biatlon_green_id" {add_view "tank_green_id"	"tank_id"	"basis"} {view start "tank_id"} {view show "tank_id"}}
{on "biatlon_yellow_id" {add_view "tank_yellow_id"	"tank_id"	"basis"} {view start "tank_id"} {view show "tank_id"}}




;=============================================
;defines of "repair" events

    {on repair
	    {if component "turret"
    		{view stop "smoke3"}
            {call "update_turret"}
            {tags remove "turret_brake"}
			{components "turret_ring" repair}
			{if tagged "crit_system_destroyed2"
		{tags remove "crit_system_destroyed2"}
		 else
		  {if tagged "crit_system_destroyed"
		   {tags remove "crit_system_destroyed"}
		  }
            ; else
		 ; {if tagged "crit_system_destroyed3"
		  ; {tags remove "crit_system_destroyed3"}
		  ;} 		  
		}
            {tags remove "turret_ring_broken"}
        else component "body"
          	{view stop "smoke4"}
			{tags remove "body_brake_apcr"}
          	  {call "update_turret"}
          	 ; {tags remove "turret_stopped_by_body"} ;APCR
          	  {tags remove "body_brake"}
          	  {able "select" 1}
        else component "engine"
            {tags remove "engine_brake"}
	{if tagged "crit_system_destroyed2"
		{tags remove "crit_system_destroyed2"}
		 else
		  {if tagged "crit_system_destroyed"
		   {tags remove "crit_system_destroyed"}
		  }
            ; else
		 ; {if tagged "crit_system_destroyed3"
		  ; {tags remove "crit_system_destroyed3"}
		  ;} 		  
		}
	{call "update_power"}
	{call "update_moveability"}

	{components "ammo_storage_mgun" repair}
	{components "ammo_storage_autocannon" repair}
	{components "ammo_storage_main" repair}
	{components "fuel_tank_internal_a" repair}
	{components "fuel_tank_internal_b" repair}
	{components "fuel_tank_internal_c" repair}
	{components "fuel_tank_internal_d" repair}

        else component "trackleft"
		{call "update_moveability"}
        else component "trackright"
		{call "update_moveability"}

        }
	{call "update_lights"}
    }
	{on "specability"
		{if not flag "specability"
			{set "specability" 1}
			{damage_report "body" "heavy_weap_disabled"}
			{components "hweap_indicator" break}
			{call "update_weaponry"}
		else 
			{set "specability" 0}
			{damage_report "body" "heavy_weap_enabled"}
			{components "hweap_indicator" repair}
			{call "update_weaponry"}
		}
	}
;============================

	{on "heavy_blast_hit"
	{components "body" break}
		{call "mp_destroy"}
	{if explosive_amount 4000	;bit more than fully loaded Msta-S
					{call "ammo_damage800"}
				else explosive_amount 2000
					{call "ammo_damage400"}
	else
		{if component "shield"
			("cut_shield_part" args "shieldr1")
			("cut_shield_part" args "shieldr2")
			("cut_shield_part" args "shieldr3")
			("cut_shield_part" args "shieldr4")
			("cut_shield_part" args "shieldr5")
			("cut_shield_part" args "shieldr6")
			("cut_shield_part" args "shieldr7")
			("cut_shield_part" args "shieldr8")
			("cut_shield_part" args "shieldr9")
			("cut_shield_part" args "shieldr10")
			("cut_shield_part" args "shieldr11")
			("cut_shield_part" args "shieldr12")
			("cut_shield_part" args "shieldr13")
			("cut_shield_part" args "shieldr14")
			("cut_shield_part" args "shieldr15")
			("cut_shield_part" args "shieldr16")
			("cut_shield_part" args "shieldl1")
			("cut_shield_part" args "shieldl2")
			("cut_shield_part" args "shieldl3")
			("cut_shield_part" args "shieldl4")
			("cut_shield_part" args "shieldl5")
			("cut_shield_part" args "shieldl6")
			("cut_shield_part" args "shieldl7")
			("cut_shield_part" args "shieldl8")
			("cut_shield_part" args "shieldl9")
			("cut_shield_part" args "shieldl10")
			("cut_shield_part" args "shieldl11")
			("cut_shield_part" args "shieldl12")
			("cut_shield_part" args "shieldl13")
			("cut_shield_part" args "shieldl14")
			("cut_shield_part" args "shieldl15")
			("cut_shield_part" args "shieldl16")
		}
		{if component "turret"
			{if rand 0.8 {kill_crew "commander"}}
			{if rand 0.8 {kill_crew "commander1"}}
			{if rand 0.8 {kill_crew "charger"}}
			{if rand 0.8 {kill_crew "gunner"}}
			{if rand 0.8 {kill_crew "gunner1"}}
			{if rand 0.8 {kill_crew "gunner2"}}
		else component "body"
			{if rand 0.5 {call "tear_turret"}}
			{if rand 0.8 {kill_crew "commander"}}
			{if rand 0.8 {kill_crew "commander1"}}
			{if rand 0.8 {kill_crew "charger"}}
			{if rand 0.8 {kill_crew "gunner"}}
			{if rand 0.8 {kill_crew "gunner1"}}
			{if rand 0.8 {kill_crew "gunner2"}}
			{if rand 0.8 {kill_crew "driver"}}
			{if rand 0.8 {kill_crew "driver1"}}
			{if rand 0.5 {kill_crew "seat1"}}			{if rand 0.5 {kill_crew "seat2"}}
			{if rand 0.5 {kill_crew "seat3"}}			{if rand 0.5 {kill_crew "seat4"}}
			{if rand 0.5 {kill_crew "seat5"}}			{if rand 0.5 {kill_crew "seat6"}}
			{if rand 0.5 {kill_crew "seat7"}}			{if rand 0.5 {kill_crew "seat8"}}
			{if rand 0.5 {kill_crew "seat9"}}			{if rand 0.5 {kill_crew "seat10"}}
			{if rand 0.5 {kill_crew "seat11"}}			{if rand 0.5 {kill_crew "seat12"}}
			{if rand 0.5 {kill_crew "seat13"}}			{if rand 0.5 {kill_crew "seat14"}}
			{if rand 0.5 {kill_crew "seat15"}}			{if rand 0.5 {kill_crew "seat16"}}
			{if rand 0.5 {kill_crew "seat17"}}			{if rand 0.5 {kill_crew "seat18"}}
			{if rand 0.5 {kill_crew "seat19"}}			{if rand 0.5 {kill_crew "seat20"}}
			{if rand 0.5 {kill_crew "seat21"}}			{if rand 0.5 {kill_crew "seat22"}}
			{if rand 0.5 {kill_crew "seat23"}}			{if rand 0.5 {kill_crew "seat24"}}
			{if rand 0.5 {kill_crew "seat25"}}
		else
			{if rand 0.3 {call "tear_turret"}}
			{if rand 0.5 {kill_crew "commander"}}
			{if rand 0.5 {kill_crew "commander1"}}
			{if rand 0.5 {kill_crew "charger"}}
			{if rand 0.5 {kill_crew "gunner"}}
			{if rand 0.5 {kill_crew "gunner1"}}
			{if rand 0.5 {kill_crew "gunner2"}}
			{if rand 0.5 {kill_crew "driver"}}
			{if rand 0.5 {kill_crew "driver1"}}
		}
		{if rand 0.5 {kill_crew "seat1"}}		{if rand 0.5 {kill_crew "seat2"}}
		{if rand 0.5 {kill_crew "seat3"}}		{if rand 0.5 {kill_crew "seat4"}}
		{if rand 0.5 {kill_crew "seat5"}}		{if rand 0.5 {kill_crew "seat6"}}
		{if rand 0.5 {kill_crew "seat7"}}		{if rand 0.5 {kill_crew "seat8"}}
		{if rand 0.5 {kill_crew "seat9"}}		{if rand 0.5 {kill_crew "seat10"}}
		{if rand 0.5 {kill_crew "seat11"}}		{if rand 0.5 {kill_crew "seat12"}}
		{if rand 0.5 {kill_crew "seat13"}}		{if rand 0.5 {kill_crew "seat14"}}
		{if rand 0.5 {kill_crew "seat15"}}		{if rand 0.5 {kill_crew "seat16"}}
		{if rand 0.5 {kill_crew "seat17"}}		{if rand 0.5 {kill_crew "seat18"}}
		{if rand 0.5 {kill_crew "seat19"}}		{if rand 0.5 {kill_crew "seat20"}}
		{if rand 0.5 {kill_crew "seat21"}}		{if rand 0.5 {kill_crew "seat22"}}
		{if rand 0.5 {kill_crew "seat23"}}		{if rand 0.5 {kill_crew "seat24"}}
		{if rand 0.5 {kill_crew "seat25"}}
	}
	}
	{on "heavy_blast_hit_add"
	{components "body" break}
		{call "mp_destroy"}
	{if explosive_amount 4000	;bit more than fully loaded Msta-S
					{call "ammo_damage800"}
				else explosive_amount 2000
	else
		{components "body" break}
		{call "mp_destroy"}
		{kill_crew "commander"}
		{kill_crew "commander1"}
		{kill_crew "charger"}
		{kill_crew "gunner"}
		{kill_crew "gunner1"}
		{kill_crew "gunner2"}
		{kill_crew "driver"}
		{kill_crew "driver1"}
		{kill_crew "seat1"}		{kill_crew "seat2"}
		{kill_crew "seat3"}		{kill_crew "seat4"}
		{kill_crew "seat5"}		{kill_crew "seat6"}
		{kill_crew "seat7"}		{kill_crew "seat8"}
		{kill_crew "seat9"}		{kill_crew "seat10"}
		{kill_crew "seat11"}		{kill_crew "seat12"}
		{kill_crew "seat13"}		{kill_crew "seat14"}
		{kill_crew "seat15"}		{kill_crew "seat16"}
		{kill_crew "seat17"}		{kill_crew "seat18"}
		{kill_crew "seat19"}		{kill_crew "seat20"}
		{kill_crew "seat21"}		{kill_crew "seat22"}
		{kill_crew "seat23"}		{kill_crew "seat24"}
		{kill_crew "seat25"}

	
	}
	}
	{on contact
		{if effector "efp_core"
			{set "efp_core" 1}
			{delay 1 {if flag "efp_core" {set "efp_core" 0}}}
		}
    }
	{on "sp_convoy_attack"	;for sp only
		{spawn "sp_convoy_assistor" "basis" x no_normal no_position}
	}

	{on "bullet_stuck"	
		{if not stuff "ic" and not stuff "gr_ic"
			{if not stuff "fg" and not stuff "fr" and not stuff "bullet"
				{burn fx "hit_tank_armor_not_pierce" fake}
			}
		}
;		{if not armor_health 1 and not flag "broken"
		{if not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "tank_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}
	{on "bullet_reflect"	
;		{if not armor_health 1 and not flag "broken"
		{if not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "tank_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}	
	{on "talk_target_destroyed"
		{call "destroyed_by_spy"}
		{talk "tank_leave"}; это заглушка! удалить после того, как для talk "body_broken" добавят озвучку - пустой толк скипается системой
		{call "talk_target_destroyed_tank"}
	}	
	{on "trailer_link"
		{play_sound "trailer_link"}
	}
	{on "detach"
		{play_sound "detach"}
	}
	("action_play_sound_and_check_stop" action(round_sandbag)			delay_next_sound(2))			;{on "round_sandbag...
	("action_play_sound_and_check_stop" action(camouflage)				delay_next_sound(2))			;{on "camouflage...
	("action_play_sound_and_check_stop" action(build_supp_point)		delay_next_sound(3))			;{on "build_supp_point...
}; end of "tank"
;-------------------------


;-------------------------

{"opened tank"
        {on "explosive_broken" overload
                {call "explosion"}
        }
}

{"turret"
	{on spawn
		{call "update_turret"}
	}
	{on "turret_break" overload
		{components "turret" break}
	}
	{on break
		{if component "turret"
			{call "update_turret"}
			{spawn "tank_die_particle" "Turret"}
			{spawn "circledust_norm" "Turret"}
			{view start "smoke3"}
			(mod not "mp"
				{set "smoke3" 1}
				{call "emit_by_turret"}
			)
			{delay 10
				{view stop "smoke3"}
				{set "smoke3" 0}
				(mod not "mp"
					{call "emit_by_turret"}
				)
			}
		}
	}
	{on "emit_by_turret"
		{call "check_burn_emit"}
	}
	{on "tear_turret"
		{if not flag "turret_teared"
			{kill_crew "gunner"}
			{kill_crew "charger"}
			{set "turret_teared" 1}
			{components "turret" destroy}
			{components "gun" destroy}
			{call "explosion"}
			(mod "mp"
				{call "mp_destroy"}
			)
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret" id "turret"
;					{impulse dir 0.5 1}
					{impulse up 7 4  rnd_dir 2 2}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}
					{delay 0.1
						{volumes "gun" disable obstacle}
					}
					{bone cut "enumerator"}
					{bone cut "enumerator1"}
					{bone cut "enumerator2"}
					{bone cut "enumerator3"}
				}
			}
		}
	}
	{on "slice_load"
		{if name "turret"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}

	{on "cut_parts"
		{if flag "turret_teared"
			{bone cut "turret"}
		else
                    {call "tear_turret"}
		}
	}
}
{"with_gun turret"
	{on spawn
		{volumes "gun_recoil" disable blast}
	}
	{on fire "gun"
		{volumes "gun_recoil" enable blast}
		{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
		{delay 0.5 {volumes "gun_recoil" disable blast}}

	}
	{on blast_hit
		{if stuff "turret_dir_detector"
			{if volume "recoil_gun_front"  {ani_play "fire_front"} {ani_play "fire_front_common"}
			else volume "recoil_gun_left"  {ani_play "fire_left"} {ani_play "fire_left_common"}
			else volume "recoil_gun_right"  {ani_play "fire_right"} {ani_play "fire_right_common"}
			else volume "recoil_gun_back"  {ani_play "fire_back"} {ani_play "fire_back_common"}
			else volume "recoil_gun_central"
			}
		}
	}
}
{"vertlaunch_pu"
	{on spawn
		{volumes "gun_recoil" disable blast}
	}
	{on fire "gun2"	;can be overwritten by custom launcher define, so check
		{volumes "gun_recoil" enable blast}
		{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
		{delay 0.5 {volumes "gun_recoil" disable blast}}
	}
	{on blast_hit
		{if stuff "turret_dir_detector"
			{if volume "recoil_gun_front"  {ani_play "fire_front"} {ani_play "fire_front_common"}
			else volume "recoil_gun_left"  {ani_play "fire_left"} {ani_play "fire_left_common"}
			else volume "recoil_gun_right"  {ani_play "fire_right"} {ani_play "fire_right_common"}
			else volume "recoil_gun_back"  {ani_play "fire_back"} {ani_play "fire_back_common"}

			else volume "recoil_gun_baleft"  {ani_play "fire_bl"}
			else volume "recoil_gun_baright"  {ani_play "fire_br"}
			else volume "recoil_gun_frright"  {ani_play "fire_fr"}
			else volume "recoil_gun_frleft"  {ani_play "fire_fl"}

			else volume "recoil_gun_central"
			}
		}
	}
}
{"has_apu"
	{on "update_power" overload
		{tags remove "no_missile_control"}
		{if not work "engine"
   		  {if not work "apu"
			{tags add "no_power"}
			{components "power_indicator" break}
		  }
		else tagged "engine_cannot_start"
			{tags add "no_power"}
			{components "power_indicator" break}
		else tagged "temp_no_power"
			{tags add "no_power"}
			{components "power_indicator" break}
		else {tags remove "no_power"} {components "power_indicator" repair}
		}
		{call "update_weaponry"}
		{call "update_turret"}
	}
	{on "engine_on" overload
		{if not flag "engine_started"
		  {if not work "ppu"
		   {if not work "apu"
		    {tags add "engine_cannot_start"}
			{chassis_work 0} {components "move_indicator" break}
		   }
		  }
		}
		{set "engine_started" 1}
		{kill_delay "engine_stopped"}
		{kill_delay "engine_steam_stopped"}
		{stop_sound "engine_end"}
		{play_sound "engine" 1}
		{view start "engine_steam"}
		{call "update_power"}
		{call "update_turret"}
	}

	{on "engine_off" overload
		{if not work "ppu"
			{if not work "apu"
				{delay 8 "engine_stopped"
					{stop_sound "engine"}
					{play_sound "engine_end"}
					{tags remove "engine_cannot_start"}
					{chassis_work 0} {components "move_indicator" break}
					{set "engine_started" 0}
					{call "update_power"}
					{call "update_turret"}
				}
				{delay 16 "engine_steam_stopped"
					{view pause "engine_steam"}
				}
			else
				{delay 4 "engine_stopped"
					{stop_sound "engine"}
					{play_sound "engine_end"}
					{set "engine_started" 0}
					{call "update_power"}
					{call "update_turret"}
				}
				{delay 12 "engine_steam_stopped"
					{view pause "engine_steam"}
				}			
		  }
		else
			{delay 4 "engine_stopped"
				{stop_sound "engine"}
				{play_sound "engine_end"}
				{set "engine_started" 0}
				{call "update_power"}
				{call "update_turret"}
			}
			{delay 12 "engine_steam_stopped"
				{view pause "engine_steam"}
			}
		}
	}
}
{"has_autoloader"
;====================================
;afterarmor system by Timosh
;decreasing fire rate when autoloader broken
	{on spawn
		{delay 15 {tags remove "cw_autoloader_stuck"}{call "update_weaponry"}}
	}
	{on "check_autoloader" overload
		{if not work "autoloader"
			{weapon_work "gun" 0}
			{damage_report "autoloader" "autoloader_malfunction"}
			{tags add "cw_autoloader_stuck"}
			{delay 15 {tags remove "cw_autoloader_stuck"}{call "update_weaponry"}}
		else tagged "no_power"
			{weapon_work "gun" 0}
			{damage_report "autoloader" "autoloader_malfunction"}
			{tags add "cw_autoloader_stuck"}
			{delay 15 {tags remove "cw_autoloader_stuck"}{call "update_weaponry"}}
		else tagged "blinding_laser"
			{weapon_work "gun" 0}
			{damage_report "body" "aiming_via_gunbarrel"}
			{tags add "cw_autoloader_stuck"}
			{delay 15 {tags remove "cw_autoloader_stuck"}{call "update_weaponry"}}
		}
	}
;end of decreasing fire rate when autoloader broken
;====================================
}
{"remote_gun1"
	{on "update_gun1" overload
		{if work "gun1"
			{if not tagged "no_power"
			 {if work "stabilizer"
			  {if work "gunner_panel"
			   {if not tagged "contusion"
				{weapon_work "gun1" 1}
			   else {weapon_work "gun1" 0}}
			  else {weapon_work "gun1" 0}}
			 else {weapon_work "gun1" 0}}
			else {weapon_work "gun1" 0}}
		else {weapon_work "gun1" 0}}
	}
}

{"remote_mgun" ("update_remote_mgun" mgun(mgun))}
{"remote_mgun1" ("update_remote_mgun" mgun(mgun1))}
{"remote_mgun2" ("update_remote_mgun" mgun(mgun2))}
{"remote_mgun3" ("update_remote_mgun" mgun(mgun3))}
{"remote_mgun4" ("update_remote_mgun" mgun(mgun4))}
{"remote_mgun5" ("update_remote_mgun" mgun(mgun5))}
{"remote_mgun6" ("update_remote_mgun" mgun(mgun6))}

{"remote_turret"
	{on "update_turret"	overload
		{if not work "turret"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "body"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "turret_move_engine"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else tagged "no_power"
			{ik_enable "turret" 0}
		else tagged "contusion" 
			{ik_enable "turret" 0}
		else
			{ik_enable "turret" 1}
		}
	}
	{on "emit_by_turret" overload
		{if not work "turret"
			{if tagged "chassis_brake"
				{call "check_burn_emit"}
				{delay 1 {crew_emit}}
				{delay 2 {crew_emit}}
				{delay 3 {crew_emit}}
			}
		}
	}
	{on "update_moveability"
		{call "emit_by_turret"}
	}
}
{"cw_panorama"
	{on "update_cw_panorama"
	   {if operatable
		{if work "additional_triplex"
			 {if work "commander_triplex"
				  {if not tagged "contusion"
					{if crew_in_place "commander"
						{if not tagged "no_power"
							{call "cw_panorama_work"}
						else {call "cw_panorama_off"}}
					else {call "cw_panorama_off"}}
				  else {call "cw_panorama_off"}}
			 else {call "cw_panorama_off"}}
		else {call "cw_panorama_off"}}
	   else {call "cw_panorama_instant_off"}}
	}
	{on "cw_panorama_work"
		{if not tagged "cw_panorama_work"
			{ani_play "panorama" callback}
		}
		{tags add "cw_panorama_work"}
	}
	{on "cw_panorama_off"
		{tags remove "cw_panorama_work"}
	}	
	{on "cw_panorama_instant_off"
		{tags remove "cw_panorama_work"}
		{ani_stop "panorama"}
	}	
	{on animation_end "panorama"
		{if tagged "cw_panorama_work" {ani_play "panorama" callback}}
	}
}
;{"medium tank turret"
;	{on bullet_hit
;		{if stuff "big shell fg"
;			{if rand 0.2
;				{call "tear_turret"}
;			}
;		}
;	}
;}

{"light tank turret"
	{on bullet_hit
		{if volume "turret"
			{if stuff "big shell fg"
				;{if rand 0.8
					{call "tear_turret"}
					{kill_crew "commander"}
				;}
			}
		}
	}
}

{"light_turret" ; turret for btr, car, ...
	{on bullet_hit
		{if volume "turret"
			{if stuff "shell"
				{call "tear_turret"}
			}
		}
	}
}

{"armored_car"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
            {spawn "dust_shot_small" "basis"}
            {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on blast_hit
		{if min_energy 8
			{impulse up 2 0.5 dir 1 0.2}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 2 r0 4 r1 9}
		{impulse up 0.7 0.3 dir 0.2 0.1}
	}
(include "tank-armoredcar.inc")

}
{"light tank"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on blast_hit
		{if min_energy 14
			{impulse up 3 0.1 dir 6 0.1}
			{if volume "turret"
				{call "tear_turret"}
				{kill_crew "commander"}
			}
		else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 8 r0 6 r1 12}
		{impulse up 0.5}
	}
	{on "_burn" overload
		("anti_fire" burn_prob(0.7) fastburn_or_exp_prob(0.4) expos_prob(0.1))
	}
(include "tank-light.inc")
}

{"medium tank"
	{inflammation_time 30}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
	}

	{on blast_hit
		{if min_energy 16
			{impulse up 2.5 0.1 dir 4 0.1}
			{if volume "turret"
				;{if rand 0.8
					{call "tear_turret"}
					{kill_crew "commander"}
					{kill_crew "gunner1"}
					{kill_crew "gunner2"}
				;}
			}
		else min_energy 9
			{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 16 r0 4 r1 12}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
	{on "_burn" overload
		("anti_fire" burn_prob(0.6) fastburn_or_exp_prob(0.4) expos_prob(0.2))
	}
(include "tank-medium.inc")
}

{"heavy tank"
	{inflammation_time 35}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}	
	}
	{on fire "gun" 
    		  {spawn "dust_shot_big" "basis"}
    		  {spawn "tank_canon_fire" "Foresight1" x}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
		{view start "zenite_smoke"}
		{view pause "smoke_add"}
		{view pause "flashbarrel_gun"}
			{delay 5
				{view pause "zenite_smoke"}
			}
		}
	}
	{on fire "mgun"
        	{spawn "mgun_smoke" "fxshell" x}  
        	{spawn "mgun_smoke" "Foresight3" x}  
		{ani_play "fire_mgun"}    

	}

	{on blast_hit
		{if min_energy 20
			{impulse up 1.5 0.1 dir 2.5 0.1}
			{if volume "turret"
				;{if rand 0.5
					{call "tear_turret"}
					{kill_crew "commander"}
					{kill_crew "gunner1"}
					{kill_crew "gunner2"}
				;}
			}
		else min_energy 3
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
                {blastwave c4 20 r0 6 r1 14}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
	{on "_burn" overload
		("anti_fire" burn_prob(0.5) fastburn_or_exp_prob(0.4) expos_prob(0.3))
	}
(include "tank-heavy.inc")
}
;/////////////////////////////////////////////////
;==============================================================

;Tanks for AAS
{"armored_car_M tank"
	{inflammation_time 20}
	{on spawn 
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
		{call "update_syst_on_spawn"}
	}
	{on fire "gun" 
            {spawn "dust_shot_small" "basis"}
            {spawn "tank_canon_fire_small" "Foresight1" x}
            ("cw_check_shooting" weap_id(gun))
	}
	{on blast_hit
	  {if volume "mrap"
	  else
		{if min_energy 22
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
			{call "heavy_blast_hit_add"}
		else min_energy 15
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
		 else min_energy 8
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
	   }
	  }
;	   {if min_energy 1
;			{if volume "gun"
;				{components "gun" break}
;			}
;	   }
	}
	{on "_explosion" 
		{blastwave c4 1.2 r0 2 r1 5}
		{impulse up 0.11 0.1 dir 0.2 0.1}
	}
	{on "init_burnout" overload
		{add_view "burnout_ifv1" "ammo_burnout1" "turret"}
		{add_view "burnout_ifv2" "ammo_burnout2" "turret"}
		{add_view "burnout_ifv3" "ammo_burnout3" "turret"}
		{add_view "burnout_ifv4" "ammo_burnout4" "turret"}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{call "sink"}
		else water_level 1.2
			{if not work "hull_integrity"
				{impulse up 0.1}
				{able "sinking" 1}
				{crew_emit}
			}
		}
	}

	(include "armored_car_m.inc")
	{on "_burn" overload
		("anti_fire" burn_prob(0.7) fastburn_or_exp_prob(0.4) expos_prob(0.05))
	}
	{on "update_turret" overload
		{if not work "turret"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "body"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "turret_move_engine"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else tagged "contusion" 
			{ik_enable "turret" 0}
		else
			{ik_enable "turret" 1}
		}
	}
}

{"4_wheels"
     {on "_update_wheel_mover"
		{if tagged "4_wheel_broken"
			{movement_limit slow}
		else tagged "3_wheel_broken"
			{movement_limit slow}
		else tagged "2_wheel_broken"
			{movement_limit slow}
		else tagged "1_wheel_broken"
			{movement_limit slow}
		else
;			{set "mover_damaged" 0}
		}
		{if tagged "3_wheel_teared"
			{set "mover_damaged" 1}
			{chassis_work 0} {components "move_indicator" break}
		else tagged "2_wheel_teared"
			{set "mover_damaged" 1}
			{chassis_work 0} {components "move_indicator" break}
		else tagged "1_wheel_teared"
			{set "mover_damaged" 1}
			{chassis_work 0} {components "move_indicator" break}
		else
			{set "mover_damaged" 0}
		}
     }
}
{"6_wheels"
     {on "_update_wheel_mover"
		{if tagged "4_wheel_broken"
			{movement_limit slow}
		else tagged "3_wheel_broken"
			{movement_limit slow}
		else tagged "2_wheel_broken"
			{movement_limit slow}
		else tagged "1_wheel_broken"
			{movement_limit normal}
		else
;			{set "mover_damaged" 0}
		}
		{if tagged "3_wheel_teared"
			{set "mover_damaged" 1}
			{chassis_work 0} {components "move_indicator" break}
		else tagged "2_wheel_teared"
			{set "mover_damaged" 1}
			{chassis_work 0} {components "move_indicator" break}
		else tagged "1_wheel_teared"
			{movement_limit slow}
		else
			{set "mover_damaged" 0}
		}
     }
}
{"8_wheels"
     {on "_update_wheel_mover"
		{if tagged "4_wheel_broken"
;			{set "mover_damaged" 1}
;			{chassis_work 0}
			{movement_limit slow}
		else tagged "3_wheel_broken"
			{movement_limit slow}
		else tagged "2_wheel_broken"
			{movement_limit normal}
		else
;			{set "mover_damaged" 0}
		}
		{if tagged "3_wheel_teared"
			{set "mover_damaged" 1}
			{chassis_work 0} {components "move_indicator" break}
		else tagged "2_wheel_teared"
			{movement_limit slow}
		else tagged "1_wheel_teared"
			{movement_limit slow}
		else
			{set "mover_damaged" 0}
		}
     }
}

{"light_M tank"
	{inflammation_time 20}
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
		{call "update_syst_on_spawn"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
                    ("cw_check_shooting" weap_id(gun))
	}
	{on blast_hit
	  {if volume "mrap"
	  else
		{if min_energy 22
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
			{call "heavy_blast_hit_add"}
		else  min_energy 15
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
		 else min_energy 10
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
	    }
	   }
;		{if min_energy 1.5
;			{if volume "gun"
;				{components "gun" break}
;			}
;	    }
	}
	{on "_explosion" 
		{blastwave c4 1.2 r0 2 r1 5}
		{impulse up 0.11 0.1 dir 0.2 0.1}
	}
	{on "init_burnout" overload
		{add_view "burnout_ifv1" "ammo_burnout1" "turret"}
		{add_view "burnout_ifv2" "ammo_burnout2" "turret"}
		{add_view "burnout_ifv3" "ammo_burnout3" "turret"}
		{add_view "burnout_ifv4" "ammo_burnout4" "turret"}
	}
	{on "_burn" overload
		("anti_fire" burn_prob(0.7) fastburn_or_exp_prob(0.4) expos_prob(0.1))
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{call "sink"}
		else water_level 1.2
			{if not work "hull_integrity"
				{impulse up 0.1}
				{able "sinking" 1}
				{crew_emit}
			}
		}
	}
	(include "tank-light_m.inc")
	{on "update_turret" overload
		{if not work "turret"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "body"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "turret_move_engine"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else tagged "contusion" 
			{ik_enable "turret" 0}
		else
			{ik_enable "turret" 1}
		}
	}
}

{"medium_M tank"
	{inflammation_time 30}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{call "update_syst_on_spawn"}
	}
;	{on "init_burnout"
;	      {if rand 0.3
;			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
;			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
;			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
;			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
;	       }
;	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
	         ("cw_check_shooting" weap_id(gun))
	}

	{on blast_hit
	  {if volume "mrap"
	  else
		{if min_energy 30
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
			{call "heavy_blast_hit_add"}
		else  min_energy 23
			{impulse up 2.5 0.1 dir 4 0.1}
			;{if rand 0.8
				{call "heavy_blast_hit"}
			;}
		else min_energy 21 and not hit_side front

			{impulse up 0.7 0.2 dir 1.5 0.2}
			;{if rand 0.66
				{call "heavy_blast_hit"}
			;}
		}
	  }
;		{if min_energy 3
;			{if volume "gun"
;				{components "gun" break}
;			}
;	    }

	}
	{on "_explosion"
		{blastwave c4 3 r0 3 r1 4}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
	{on "_burn" overload
		("anti_fire" burn_prob(0.6) fastburn_or_exp_prob(0.4) expos_prob(0.2))
	}
(include "tank-medium_m.inc")
}

{"heavy_M tank"
	{inflammation_time 40}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{call "update_syst_on_spawn"}
	}
;	{on "init_burnout"
;	      {if rand 0.3
;			{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
;			{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
;			{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
;			{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
;	       }
;	}
;чтобы не было дыма на ЗПУ
;	{on fire "mgun"
 ;       	{spawn "mgun_smoke" "fxshell" x}  
  ;      	{spawn "mgun_smoke" "Foresight3" x}  
;		{ani_play "fire_mgun"}    
;
;	}
	{on "check_autoloader"
		{if tagged "blinding_laser"
			{weapon_work "gun" 0}
			{damage_report "body" "aiming_via_gunbarrel"}
			{tags add "cw_autoloader_stuck"}
			{delay 15 {tags remove "cw_autoloader_stuck"}{call "update_weaponry"}}
		}
	}
	{on blast_hit
	  {if volume "mrap"
	  else
		{if min_energy 30
			{impulse up 2 0.5 dir 1 0.2}
			{call "heavy_blast_hit"}
			{call "heavy_blast_hit_add"}
		else min_energy 25
			{impulse up 1.5 0.1 dir 2.5 0.1}
			;{if rand 0.85
				{call "heavy_blast_hit"}
			;}
		else min_energy 21.5 and not hit_side front
			{impulse up 0.25 0.1 dir 0.35 0.1}
			;{if rand 0.66
				{call "heavy_blast_hit"}
			;}
		}
	  }
;		{if min_energy 3
;			{if volume "gun"
;				{components "gun" break}
;			}
;	    }
	}
	{on "_explosion"
		{blastwave c4 3 r0 3 r1 4}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
	{on "_burn" overload
		("anti_fire" burn_prob(0.5)fastburn_or_exp_prob(0.4) expos_prob(0.3))
	}
(include "tank-heavy_m.inc")
}
(define "cw_blow_panels"
		{on spawn {tags remove "cwbp_firing"}}
		{on fire "gun" {tags add "cwbp_firing"} {delay 5 {tags remove "cwbp_firing"}}}
		{on "ammo_burnout" overload
			{if not tagged "cwbp_firing"
				{if volume "%volume"
					{call "blow_burnout"}
					{start_sound "detonation/ammo_burnout"}
					{spawn "ex_air_big"}
				else {inherited}}
			else {inherited}}
		}
		{on "blow_burnout"
			{delay_ex 0
				{start_sound "detonation/ammo_burnout"}
				{burn volume "%volume" fx "burnout_blow_panel1" time 10 fake}
				{delay 1.4 0.4 {burn volume "%volume" fx "burnout_blow_panel2" time 10 fake}}
				{delay 1 1 {burn volume "%volume" fx "burnout_blow_panel3" time 10 fake}}
				{delay 5 1 {burn volume "%volume" fx "burnout_blow_panel4" time 15 fake}}
				{call "%panels"}
			}
			
		}
		{on "%panels"
				{view start "blow_burnout1"}
				{delay 1.4 0.4	{view start "blow_burnout2"}}
				{delay 3 1	{view start "blow_burnout3"}}
				{delay 5 1	{view start "blow_burnout4"}}
		}
)
{"cw_blow_panels" ("cw_blow_panels" volume(ammo_storage_main) panels(blow_panels))}
{"cw_blow_panels1" ("cw_blow_panels" volume(ammo_storage_main1) panels(blow_panels1))}
{"cw_blow_panels2" ("cw_blow_panels" volume(ammo_storage_main2) panels(blow_panels2))}
{"cw_blow_panels3" ("cw_blow_panels" volume(ammo_storage_main3) panels(blow_panels3))}
{"cw_blow_panels4" ("cw_blow_panels" volume(ammo_storage_main4) panels(blow_panels4))}
{"cw_blow_panels5" ("cw_blow_panels" volume(ammo_storage_main5) panels(blow_panels5))}
{"remote_gun"
	{on "update_gun" overload
		{if work "gun"
			{if not tagged "no_power"
			 {if work "stabilizer"
			  {if work "gunner_panel"
				{if not flag "specability"
				 {if not tagged "contusion" 
					{if work "autoloader"
						{weapon_work "gun" 1}
					else {weapon_work "gun" 0}}
				 else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			   else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
			else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
}

{"remote_autocannon"
	{on "update_gun" overload
		{if work "gun"
			{if not tagged "no_power"
			 {if work "stabilizer"
			  {if work "gunner_panel"
			    {if not tagged "contusion" 
					{weapon_work "gun" 1}
			    else {weapon_work "gun" 0}}
			  else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
			else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
}
(include "tanks_settings.inc")
;==========================================================
{"cwps3_fixmarker1"
	{on "forward_proj_point" overload
		{if not tagged "destroyed" {if velocity 15 {with_linked_entity "cwps_proj_point" {if not flag "stop" {if not tagged "stop_forward" {ani_wind "forward1" end} {tags add "forward1_start forward"}}}}
		else {with_linked_entity "cwps_proj_point" {ani_wind "forward1" begin}} }}
	}
}
{"cwps3_fixmarker2"
	{on "forward_proj_point" overload
		{if not tagged "destroyed" {if velocity 15 {with_linked_entity "cwps_proj_point" {if not flag "stop" {if not tagged "stop_forward" {ani_wind "forward2" end} {tags add "forward2_start forward"}}}}
		else {with_linked_entity "cwps_proj_point" {ani_wind "forward2" begin}} }}
	}
}
{"cwps3_fixmarker3"
	{on "forward_proj_point" overload
		{if not tagged "destroyed" {if velocity 15 {with_linked_entity "cwps_proj_point" {if not flag "stop" {if not tagged "stop_forward" {ani_wind "forward3" end} {tags add "forward3_start forward"}}}}
		else {with_linked_entity "cwps_proj_point" {ani_wind "forward3" begin}} }}
	}
}
{"cwps3_fixmarker4"
	{on "forward_proj_point" overload
		{if not tagged "destroyed" {if velocity 15 {with_linked_entity "cwps_proj_point" {if not flag "stop" {if not tagged "stop_forward" {ani_wind "forward4" end} {tags add "forward4_start forward"}}}}
		else {with_linked_entity "cwps_proj_point" {ani_wind "forward4" begin}} }}
	}
}
{"cwps3_fixmarker5"
	{on "forward_proj_point" overload
		{if not tagged "destroyed" {if velocity 15 {with_linked_entity "cwps_proj_point" {if not flag "stop" {if not tagged "stop_forward" {ani_wind "forward5" end} {tags add "forward5_start forward"}}}}
		else {with_linked_entity "cwps_proj_point" {ani_wind "forward5" begin}} }}
	}
}
{"cwps3_fixmarker6"
	{on "forward_proj_point" overload
		{if not tagged "destroyed" {if velocity 15 {with_linked_entity "cwps_proj_point" {if not flag "stop" {if not tagged "stop_forward" {ani_wind "forward6" end} {tags add "forward6_start forward"}}}}
		else {with_linked_entity "cwps_proj_point" {ani_wind "forward6" begin}} }}
	}
}
;==========================================================
;KAZ system by Timosh
;==========================================================
{"KAZ"
 (define "kaz_shot"
	volume "kaz_hitzone_%0"
		{spawn "cw_cumulative_frestrict" {delay 0.1 {delete}}}
		{bullet_detonate}
		  {spawn "ex_air_sm" "kaz_%0"}
		  {spawn "startsmoke_cali" "kaz_shot_a_%0" x}
		  {spawn "ex_air_norm" "kaz_shot_b_%0" x}
		  {spawn "tank_cannon_fire" "kaz_shot_b_%0" x}
		{bone hide "kaz_%0"}
		{volumes "kaz_%0" disable contact bullet blast contact_ground visible select}
		{volumes "kaz_hitzone_%0" disable bullet contact}
		{volumes "kaz_hitzone_%0a" disable bullet contact}
		{volumes "kaz_%0" enable touch}
		{volumes "kaz_hitzone_%0" enable touch}
		{tags add "kaz_%0_empty"}
	else volume "kaz_hitzone_%0a"
		{spawn "cw_cumulative_frestrict" {delay 0.1 {delete}}}
		{bullet_detonate}
		  {spawn "ex_air_sm" "kaz_%0"}
		  {spawn "startsmoke_cali" "kaz_shot_a_%0" x}
		  {spawn "ex_air_norm" "kaz_shot_b_%0" x}
		  {spawn "tank_cannon_fire" "kaz_shot_b_%0" x}
		{bone hide "kaz_%0"}
		{volumes "kaz_%0" disable contact bullet blast contact_ground visible select}
		{volumes "kaz_hitzone_%0" disable bullet contact}
		{volumes "kaz_hitzone_%0a" disable bullet contact}
		{volumes "kaz_%0" enable touch}
		{volumes "kaz_hitzone_%0" enable touch}
		{tags add "kaz_%0_empty"}
 )
 (define "kaz_destroyed"
            volume "kaz_%0"
		{spawn "ex_air_norm"}
		{fragments c4 0.5 r0 0.3 r1 0.4}
		{bone hide "kaz_%0"}
		{volumes "kaz_%0" disable contact bullet blast contact_ground visible select}
		{volumes "kaz_hitzone_%0" disable bullet contact}
		{volumes "kaz_%0" enable touch}
		{volumes "kaz_hitzone_%0" enable touch}
		{tags add "kaz_%0_empty"}
		{components "kaz%0" break}


)
{on "kaz_turn_on"
		{tags add "kaz_working"}
		{if operatable
		  {if not tagged "no_power"
			{call "kaz_enable"}
		  }
		}
}
{on "kaz_enable"
		(define "kaz_single_turn_on"
			{if work "kaz%0" {if not tagged "kaz_%0_empty" {volumes "kaz_hitzone_%0" enable bullet contact}}}
		)
		   {if work "kaz_radar"
			("kaz_single_turn_on" args 01)
			("kaz_single_turn_on" args 02)
			("kaz_single_turn_on" args 03)
			("kaz_single_turn_on" args 04)
			("kaz_single_turn_on" args 05)
			("kaz_single_turn_on" args 06)
			("kaz_single_turn_on" args 07)
			("kaz_single_turn_on" args 08)
			("kaz_single_turn_on" args 09)
			("kaz_single_turn_on" args 10)
			("kaz_single_turn_on" args 11)
			("kaz_single_turn_on" args 12)
			("kaz_single_turn_on" args 13)
			("kaz_single_turn_on" args 14)
			("kaz_single_turn_on" args 15)
			("kaz_single_turn_on" args 16)
			("kaz_single_turn_on" args 17)
			("kaz_single_turn_on" args 18)
			("kaz_single_turn_on" args 19)
			("kaz_single_turn_on" args 20)
			("kaz_single_turn_on" args 21)
			("kaz_single_turn_on" args 22)
			("kaz_single_turn_on" args 23)
			("kaz_single_turn_on" args 24)
			("kaz_single_turn_on" args 25)
			("kaz_single_turn_on" args 26)
			("kaz_single_turn_on" args 27)
			("kaz_single_turn_on" args 28)
			("kaz_single_turn_on" args 29)
		   }
}
(define "kaz_single_turn_off"
	{volumes "kaz_hitzone_%0" disable bullet contact blast visible obstacle select}
	{volumes "kaz_hitzone_%0a" disable bullet contact blast visible obstacle select touch}
)
 (define "kaz_turn_off"
		{if not flag "kaz_reloading"
			{tags remove "kaz_working"}
		}
			("kaz_single_turn_off" args 01)
			("kaz_single_turn_off" args 02)
			("kaz_single_turn_off" args 03)
			("kaz_single_turn_off" args 04)
			("kaz_single_turn_off" args 05)
			("kaz_single_turn_off" args 06)
			("kaz_single_turn_off" args 07)
			("kaz_single_turn_off" args 08)
			("kaz_single_turn_off" args 09)
			("kaz_single_turn_off" args 10)
			("kaz_single_turn_off" args 11)
			("kaz_single_turn_off" args 12)
			("kaz_single_turn_off" args 13)
			("kaz_single_turn_off" args 14)
			("kaz_single_turn_off" args 15)
			("kaz_single_turn_off" args 16)
			("kaz_single_turn_off" args 17)
			("kaz_single_turn_off" args 18)
			("kaz_single_turn_off" args 19)
			("kaz_single_turn_off" args 20)
			("kaz_single_turn_off" args 21)
			("kaz_single_turn_off" args 22)
			("kaz_single_turn_off" args 23)
			("kaz_single_turn_off" args 24)
			("kaz_single_turn_off" args 25)
			("kaz_single_turn_off" args 26)
			("kaz_single_turn_off" args 27)
			("kaz_single_turn_off" args 28)
			("kaz_single_turn_off" args 29)
  )
	{on spawn
		 ("kaz_turn_off")
		{delay 0.1 ("kaz_turn_off")}
		{set "kaz_reloading" 0}{tags remove "kaz_reloading"}{tags remove "kaz_blocked"}
	}
	{on "kaz_work"
	  {if not tagged "kaz_blocked"
	    {kill_delay "kaz_delay"}
;		{if work "kaz_radar"
			{if not flag "kaz_reloading"
				{call "kaz_turn_on"}
			else {delay 0.2 "kaz_reloading" {set "kaz_reloading" 0} {call "kaz_turn_on"}}
			}
;		}
		{if stuff "proj_pointer"
			{delay 9 "kaz_delay"
				{kill_delay "kaz_contact"}
				{kill_delay "kaz_reloading"}
				("kaz_turn_off")
			}
	;удалено - каз отключался при вкл. скриптах через 3с. 
		else
			{delay 3 "kaz_delay"
				{kill_delay "kaz_contact"}
				{kill_delay "kaz_reloading"}
				("kaz_turn_off")
			}
	    }
	  }
	}
 (define "kaz_shoot"
	     {if ("kaz_shot" args 01)
	     else ("kaz_shot" args 02)
	     else ("kaz_shot" args 03)
	     else ("kaz_shot" args 04)
	     else ("kaz_shot" args 05)
	     else ("kaz_shot" args 06)
	     else ("kaz_shot" args 07)
	     else ("kaz_shot" args 08)
	     else ("kaz_shot" args 09)
	     else ("kaz_shot" args 10)
	     else ("kaz_shot" args 11)
	     else ("kaz_shot" args 12)
	     else ("kaz_shot" args 13)
	     else ("kaz_shot" args 14)
	     else ("kaz_shot" args 15)
	     else ("kaz_shot" args 16)
	     else ("kaz_shot" args 17)
	     else ("kaz_shot" args 18)
	     else ("kaz_shot" args 19)
	     else ("kaz_shot" args 20)
	     else ("kaz_shot" args 21)
	     else ("kaz_shot" args 22)
	     else ("kaz_shot" args 23)
	     else ("kaz_shot" args 24)
	     else ("kaz_shot" args 25)
	     else ("kaz_shot" args 26)
	     else ("kaz_shot" args 27)
	     else ("kaz_shot" args 28)
	     else ("kaz_shot" args 29)
	     }
	     {set "kaz_reloading" 1}
	     ("kaz_turn_off")
	     {tags add "kaz_reloading"}
	     {delay 0.2 {call "kaz_work"}  {set "kaz_reloading" 0}  {tags remove "kaz_reloading"}}
)
	{on break
	    {if component "kaz_radar"
			{spawn "tank_die_particle"}
			{tags add "kaz_radar_damaged"}
			{if not tagged "destroyed"
				{damage_report "kaz_radar" "kaz_radar_damaged"}
			}
		else  component "kaz_radar1"
			{spawn "tank_die_particle"}
			{tags add "kaz_radar1_damaged"}
			{if not tagged "destroyed"
				{damage_report "kaz_radar1" "kaz_radar_damaged"}
			}
		else  component "kaz_radar2"
			{spawn "tank_die_particle"}
			{tags add "kaz_radar2_damaged"}
			{if not tagged "destroyed"
				{damage_report "kaz_radar2" "kaz_radar_damaged"}
			}
		else  component "kaz_radar3"
			{spawn "tank_die_particle"}
			{tags add "kaz_radar3_damaged"}
			{if not tagged "destroyed"
				{damage_report "kaz_radar3" "kaz_radar_damaged"}
			}
		else  component "kaz_radar4"
			{spawn "tank_die_particle"}
			{tags add "kaz_radar4_damaged"}
			{if not tagged "destroyed"
				{damage_report "kaz_radar4" "kaz_radar_damaged"}
			}
		else  component "kaz_radar5"
			{spawn "tank_die_particle"}
			{tags add "kaz_radar5_damaged"}
			{if not tagged "destroyed"
				{damage_report "kaz_radar5" "kaz_radar_damaged"}
			}
		else component "kaz01" else component "kaz02" else component "kaz03" else component "kaz04" 
		else component "kaz05" else component "kaz06" else component "kaz07" else component "kaz08" 
		else component "kaz09" else component "kaz10" else component "kaz11" else component "kaz12" 
		else component "kaz13" else component "kaz14" else component "kaz15" else component "kaz16" 
		else component "kaz17" else component "kaz18" else component "kaz19" else component "kaz20" 
		else component "kaz21" else component "kaz22" else component "kaz23" else component "kaz24" 
		else component "kaz25" else component "kaz26"  else component "kaz27" else component "kaz28"
		else component "kaz29"
	    }
	}
	{on repair
		(define "repair_kaz" 

		)
	     {if component "kaz_radar"
		{damage_report "kaz_radar" "kaz_radar_repaired"}
		{tags remove "kaz_radar_damaged"}
		else component "kaz_radar1"
		{damage_report "kaz_radar1" "kaz_radar:kaz_radar_repaired"}
		{tags remove "kaz_radar1_damaged"}
		else component "kaz_radar2"
		{damage_report "kaz_radar2" "kaz_radar:kaz_radar_repaired"}
		{tags remove "kaz_radar2_damaged"}
		else component "kaz_radar3"
		{damage_report "kaz_radar3" "kaz_radar:kaz_radar_repaired"}
		{tags remove "kaz_radar3_damaged"}
		else component "kaz_radar4"
		{damage_report "kaz_radar4" "kaz_radar:kaz_radar_repaired"}
		{tags remove "kaz_radar4_damaged"}
		else component "kaz_radar5"
		{damage_report "kaz_radar5" "kaz_radar:kaz_radar_repaired"}
		{tags remove "kaz_radar5_damaged"}
		else component "kaz01" ("repair_kaz" args 01) else component "kaz02" ("repair_kaz" args 02) 
		else component "kaz03" ("repair_kaz" args 03) else component "kaz04" ("repair_kaz" args 04) 
		else component "kaz05" ("repair_kaz" args 05) else component "kaz06" ("repair_kaz" args 06) 
		else component "kaz07" ("repair_kaz" args 07) else component "kaz08" ("repair_kaz" args 08) 
		else component "kaz09" ("repair_kaz" args 09) else component "kaz10" ("repair_kaz" args 10) 
		else component "kaz11" ("repair_kaz" args 11) else component "kaz12" ("repair_kaz" args 12) 
		else component "kaz13" ("repair_kaz" args 13) else component "kaz14" ("repair_kaz" args 14) 
		else component "kaz15" ("repair_kaz" args 15) else component "kaz16" ("repair_kaz" args 16) 
		else component "kaz17" ("repair_kaz" args 17) else component "kaz18" ("repair_kaz" args 18) 
		else component "kaz19" ("repair_kaz" args 19) else component "kaz20" ("repair_kaz" args 20) 
		else component "kaz21" ("repair_kaz" args 21) else component "kaz22" ("repair_kaz" args 22) 
		else component "kaz23" ("repair_kaz" args 23) else component "kaz24" ("repair_kaz" args 24) 
		else component "kaz25" ("repair_kaz" args 25) else component "kaz26" ("repair_kaz" args 26) 
		else component "kaz27" ("repair_kaz" args 27) else component "kaz28" ("repair_kaz" args 28) 
		else component "kaz29" ("repair_kaz" args 29)

	     }
	}
	{on pierce
	     {if component "kaz_radar"
		{components "kaz_radar" break}
		{burn fx "smoke_dead_tank2" fake}
	     else  component "kaz_radar1"
		{components "kaz_radar1" break}
		{burn fx "smoke_dead_tank2" fake}
	     else  component "kaz_radar2"
		{components "kaz_radar2" break}
		{burn fx "smoke_dead_tank2" fake}
	     else  component "kaz_radar3"
		{components "kaz_radar3" break}
		{burn fx "smoke_dead_tank2" fake}
	     else  component "kaz_radar4"
		{components "kaz_radar4" break}
		{burn fx "smoke_dead_tank2" fake}
	     else  component "kaz_radar5"
		{components "kaz_radar5" break}
		{burn fx "smoke_dead_tank2" fake}
		 }
	     {if ("kaz_destroyed" args 01)
	     else ("kaz_destroyed" args 02)
	     else ("kaz_destroyed" args 03)
	     else ("kaz_destroyed" args 04)
	     else ("kaz_destroyed" args 05)
	     else ("kaz_destroyed" args 06)
	     else ("kaz_destroyed" args 07)
	     else ("kaz_destroyed" args 08)
	     else ("kaz_destroyed" args 09)
	     else ("kaz_destroyed" args 10)
	     else ("kaz_destroyed" args 11)
	     else ("kaz_destroyed" args 12)
	     else ("kaz_destroyed" args 13)
	     else ("kaz_destroyed" args 14)
	     else ("kaz_destroyed" args 15)
	     else ("kaz_destroyed" args 16)
	     else ("kaz_destroyed" args 17)
	     else ("kaz_destroyed" args 18)
	     else ("kaz_destroyed" args 19)
	     else ("kaz_destroyed" args 20)
	     else ("kaz_destroyed" args 21)
	     else ("kaz_destroyed" args 22)
	     else ("kaz_destroyed" args 23)
	     else ("kaz_destroyed" args 24)
	     else ("kaz_destroyed" args 25)
	     else ("kaz_destroyed" args 26)
	     else ("kaz_destroyed" args 27)
	     else ("kaz_destroyed" args 28)
	     else ("kaz_destroyed" args 29)
	     }
	}
	{on "kaz_shell_hit"
		{if stuff "low_speed"
			{if not stuff "proj_pointer"
				{call "kaz_work_on_rpg"}
			}
	     }
	     {if stuff "proj_pointer" {call "kaz_work_on_ptur"}}
	}
	{on bullet_hit
	     {call "kaz_shell_hit"}
	}
	{on "kaz_work_on_rpg" ("kaz_shoot")}
	{on "kaz_work_on_ptur" {call "kaz_work"}}
	{on "kaz_work_on_shell"}	;usually KAZ does not work on artillery shells
	{on "other_kaz_contact"
			{if volume "kaz_hitzone" 
				  {if tagged "kaz_working"
					("kaz_turn_off")
					{kill_delay "kaz_contact"} {delay 0.5 "kaz_contact" {call "kaz_turn_on"}}
				  }
			}
			{if tagged "kaz_working"
				  {delay 9 "kaz_delay"
					{kill_delay "kaz_contact"}
					("kaz_turn_off")
				  }
			}	
	}
	{on contact
	     {if effector "proj_dummy"
			{if volume "kaz_hitzone" 
				("kaz_shoot")	{with_effector {call "destroyed_by_kaz"}}
			else	{with_effector {call "detonate"}}
			}
	      else effector "cw_cumassist_spawner" 
	      else effector "cw_cumulative_assistor" 	      
	      else effector "cw_fgassist_spawner" 
	      else effector "cw_fg_assistor" 	      
	      else effector "cw_apcrassist_spawner" 
	      else effector "cw_apcr_assistor" 	      
	      else
			{call "other_kaz_contact"}
	     }
	}
	{on "kaz_reload"
		(define "kaz_reload_single"
			tagged "kaz_%0_empty"
				{delay 0.1
					{volumes "kaz_%0" disable touch}
					{volumes "kaz_hitzone_%0" disable touch}
					{tags remove "kaz_%0_empty"}
					{volumes "kaz_%0" enable contact bullet blast contact_ground visible select}
					{bone show "kaz_%0"}
				}
		)
		{if ("kaz_reload_single" args 01)
		else ("kaz_reload_single" args 02)
		else ("kaz_reload_single" args 03)
		else ("kaz_reload_single" args 04)
		else ("kaz_reload_single" args 05)
		else ("kaz_reload_single" args 06)
		else ("kaz_reload_single" args 07)
		else ("kaz_reload_single" args 08)
		else ("kaz_reload_single" args 09)
		else ("kaz_reload_single" args 10)
		else ("kaz_reload_single" args 11)
		else ("kaz_reload_single" args 12)
		else ("kaz_reload_single" args 13)
		else ("kaz_reload_single" args 14)
		else ("kaz_reload_single" args 15)
		else ("kaz_reload_single" args 16)
		else ("kaz_reload_single" args 17)
		else ("kaz_reload_single" args 18)
		else ("kaz_reload_single" args 19)
		else ("kaz_reload_single" args 20)
		else ("kaz_reload_single" args 21)
		else ("kaz_reload_single" args 22)
		else ("kaz_reload_single" args 23)
		else ("kaz_reload_single" args 24)
		else ("kaz_reload_single" args 25)
		else ("kaz_reload_single" args 26)
		}
	
	}
	
}
{"kaz kaz_drozd"
	{on "kaz_enable" overload
		(define "kaz_single_turn_on"
			{if work "kaz%0" {if not tagged "kaz_%0_empty" {volumes "kaz_hitzone_%0" enable bullet contact} }}
		)
		   {if work "kaz_radar"
		   	   {if work "kaz_radar1"
				("kaz_single_turn_on" args 01)
				("kaz_single_turn_on" args 02)
				("kaz_single_turn_on" args 03)
				("kaz_single_turn_on" args 04)
			   }
		   	   {if work "kaz_radar2"
				("kaz_single_turn_on" args 05)
				("kaz_single_turn_on" args 06)
				("kaz_single_turn_on" args 07)
				("kaz_single_turn_on" args 08)
			   }
		   }
	}
}
{"kaz kaz_afganit"
	{on "kaz_enable" overload
		(define "kaz_single_turn_on"
			{if work "kaz%0" {if not tagged "kaz_%0_empty" 
			{volumes "kaz_hitzone_%0" enable bullet contact}
			{volumes "kaz_hitzone_%0a" enable bullet contact}
			}}
		)
		   {if work "kaz_radar"
		   	   {if work "kaz_radar1"
				("kaz_single_turn_on" args 01)
				("kaz_single_turn_on" args 02)
				("kaz_single_turn_on" args 03)
				("kaz_single_turn_on" args 04)
				("kaz_single_turn_on" args 05)
			   }
		   	   {if work "kaz_radar2"
				("kaz_single_turn_on" args 06)
				("kaz_single_turn_on" args 07)
				("kaz_single_turn_on" args 08)
				("kaz_single_turn_on" args 09)
				("kaz_single_turn_on" args 10)
			   }
		   }
	}
	{on "kaz_work_on_shell" {call "kaz_work"}}	;Afganit can intercept shells
	{on "kaz_shell_hit" overload
		{if stuff "bullet"
		 else stuff "hmgun"
		 else stuff "autocannon"
		 else stuff "cm"
		 	{if not stuff "proj_pointer"
				{call "kaz_work_on_rpg"}
			}
		 else stuff "fg"
		 	{if not stuff "proj_pointer"
				{call "kaz_work_on_rpg"}
			}
		 else stuff "apcr"
		 	{if not stuff "proj_pointer"
				{call "kaz_work_on_apcr"}
			}
	     }
	     {if stuff "proj_pointer" {call "kaz_work_on_ptur"}}
	}
	{on fire "gun2" 
		{tags add "kaz_blocked"} ("kaz_turn_off") 
		{delay 1 {tags remove "kaz_blocked"}}
	}
	{on fire "gun3" 
		{tags add "kaz_blocked"}  ("kaz_turn_off")
		{delay 1 {tags remove "kaz_blocked"}}
	}
 (define "kaz_shot_apcr"
	volume "kaz_hitzone_%0a"
		  {spawn "ex_air_sm" "kaz_%0"}
		  {spawn "startsmoke_cali" "kaz_shot_a_%0" x}
		  {spawn "ex_air_norm" "kaz_shot_b_%0" x}
		  {spawn "tank_cannon_fire" "kaz_shot_b_%0" x}
		{bone hide "kaz_%0"}
		{volumes "kaz_%0" disable contact bullet blast contact_ground visible select}
		{volumes "kaz_hitzone_%0" disable bullet contact}
		{volumes "kaz_hitzone_%0a" disable bullet contact}
		{volumes "kaz_%0" enable touch}
		{volumes "kaz_hitzone_%0" enable touch}
		{tags add "kaz_%0_empty"}
 )
	
 (define "kaz_shoot_apcr"
	     {if ("kaz_shot_apcr" args 01)
	     else ("kaz_shot_apcr" args 02)
	     else ("kaz_shot_apcr" args 03)
	     else ("kaz_shot_apcr" args 04)
	     else ("kaz_shot_apcr" args 05)
	     else ("kaz_shot_apcr" args 06)
	     else ("kaz_shot_apcr" args 07)
	     else ("kaz_shot_apcr" args 08)
	     else ("kaz_shot_apcr" args 09)
	     else ("kaz_shot_apcr" args 10)
	     }
	     {set "kaz_reloading" 1}
	     ("kaz_turn_off")
	     {tags add "kaz_reloading"}
	     {delay 0.2 {call "kaz_work"}  {set "kaz_reloading" 0}  {tags remove "kaz_reloading"}}
)
	{on "kaz_work_on_apcr"	("kaz_shoot_apcr")
	}
}
{"kaz_afganit_kurganec"
	{on "kaz_enable" overload
		(define "kaz_single_turn_on"
			{if work "kaz%0" {if not tagged "kaz_%0_empty" 
			{volumes "kaz_hitzone_%0" enable bullet contact}
			{volumes "kaz_hitzone_%0a" enable bullet contact}
			}}
		)
		   {if work "kaz_radar"
		   	   {if work "kaz_radar1"
				("kaz_single_turn_on" args 01)
				("kaz_single_turn_on" args 02)
				("kaz_single_turn_on" args 03)
				("kaz_single_turn_on" args 04)
			   }
		   	   {if work "kaz_radar2"
				("kaz_single_turn_on" args 05)
				("kaz_single_turn_on" args 06)
				("kaz_single_turn_on" args 07)
				("kaz_single_turn_on" args 08)
			   }
		   	   {if work "kaz_radar3"
				("kaz_single_turn_on" args 09)
				("kaz_single_turn_on" args 10)
				("kaz_single_turn_on" args 11)
				("kaz_single_turn_on" args 12)
			   }
		   	   {if work "kaz_radar4"
				("kaz_single_turn_on" args 13)
				("kaz_single_turn_on" args 14)
				("kaz_single_turn_on" args 15)
				("kaz_single_turn_on" args 16)
			   }
		   	   {if work "kaz_radar5"
				("kaz_single_turn_on" args 17)
				("kaz_single_turn_on" args 18)
				("kaz_single_turn_on" args 19)
				("kaz_single_turn_on" args 20)
			   }
		   }
	}
}
{"shtora"
	{on spawn
		{add_view	"shtora_work"	"shtora"	"shtora1"}
		{add_view	"shtora_work"	"shtora"	"shtora2"}
	}
	{on break
	    {if component "shtora"
		{spawn "glass_hit" "shtora"}
		{spawn "glass_hit" "shtora1"}
		{tags add "shtora_damaged"}
		{if not tagged "destroyed"
			{damage_report "shtora" "shtora:shtora_damaged"}
		}
	    }
	}
	{on repair
	     {if component "shtora"
		{damage_report "shtora" "shtora_repaired"}
		{tags remove "shtora_damaged"}
	     }
	}
	{on pierce
	     {if component "shtora"
		{components "shtora" break}
		{burn fx "smoke_dead_tank2" fake}
	     }
	}

	{on "_explosion"
		{view hide "shtora"}
	}
}
{"kaz trophy"
 (define "trophy_mortar_l_turn_on"
	{if work "trophy_mortar_l"
	      {if not tagged "trophy_l_empty"
		   {if not effector "cw_cumassist_notrophy"
			{tags add "trophy_mortar_l_working"}
			{volumes "kaz_hitzone_l1" enable bullet}
			{volumes "kaz_hitzone_l2" enable bullet}
			{volumes "kaz_hitzone_l3" enable bullet}
			{volumes "kaz_hitzone_l4" enable bullet}
		   }
	      }
	}
)
 (define "trophy_mortar_l_turn_off"
		{if not tagged "trophy_mortar_l_reloading"
			{tags remove "trophy_mortar_l_working"}
		}
		{volumes "kaz_hitzone_l1" disable bullet contact blast visible obstacle touch select}
		{volumes "kaz_hitzone_l2" disable bullet contact blast visible obstacle touch select}
		{volumes "kaz_hitzone_l3" disable bullet contact blast visible obstacle touch select}
		{volumes "kaz_hitzone_l4" disable bullet contact blast visible obstacle touch select}
)
 (define "trophy_mortar_r_turn_on"
	{if work "trophy_mortar_r"
	      {if not tagged "trophy_r_empty"
		   {if not effector "cw_cumassist_notrophy"
		    {tags add "trophy_mortar_r_working"}
			{volumes "kaz_hitzone_r1" enable bullet}
			{volumes "kaz_hitzone_r2" enable bullet}
			{volumes "kaz_hitzone_r3" enable bullet}
			{volumes "kaz_hitzone_r4" enable bullet}
		   }
	      }
	}
)
 (define "trophy_mortar_r_turn_off"
		{if not tagged "trophy_mortar_r_reloading"
			{tags remove "trophy_mortar_r_working"}
		}
		{volumes "kaz_hitzone_r1" disable bullet contact blast visible obstacle touch select}
		{volumes "kaz_hitzone_r2" disable bullet contact blast visible obstacle touch select}
		{volumes "kaz_hitzone_r3" disable bullet contact blast visible obstacle touch select}
		{volumes "kaz_hitzone_r4" disable bullet contact blast visible obstacle touch select}
)
	{on spawn
		("trophy_mortar_r_turn_off")
		("trophy_mortar_l_turn_off")
		{delay 0.1 
			("trophy_mortar_r_turn_off")
			("trophy_mortar_l_turn_off")
		}
		{delay 10 
			{tags remove "trophy_l_empty"} 
			{tags remove "trophy_l_empty"} 
		}
	}
	{on fire "kaz_l"
		{spawn "trophy_shoot" "Foresight_kaz_l" x}
		{spawn "trophy_proj_initiator" "Foresight_kaz_l" x}
		("trophy_mortar_l_turn_off")
		{tags add "trophy_mortar_l_reloading"}
		{delay 1 {tags remove "trophy_mortar_l_reloading"} ("trophy_mortar_l_turn_on")}
;		{if tagged "trophy_l_5remain" {tags remove "trophy_l_5remain"} {tags add "trophy_l_4remain"}
;		else  tagged "trophy_l_4remain" {tags remove "trophy_l_4remain"} {tags add "trophy_l_3remain"}
;		else  tagged "trophy_l_3remain" {tags remove "trophy_l_3remain"} {tags add "trophy_l_2remain"}
		{if tagged "trophy_l_3remain" {tags remove "trophy_l_3remain"} {tags add "trophy_l_2remain"}
		else  tagged "trophy_l_2remain" {tags remove "trophy_l_2remain"} {tags add "trophy_l_1remain"}
		else  tagged "trophy_l_1remain" {tags remove "trophy_l_1remain"} {tags add "trophy_l_empty"} {delay 10 {tags remove "trophy_l_empty"}}
		else {tags add "trophy_l_5remain"}
		}
	}
	{on fire "kaz_r"
		{spawn "trophy_shoot" "Foresight_kaz_r" x}
		{spawn "trophy_proj_initiator" "Foresight_kaz_r" x}
		("trophy_mortar_r_turn_off")
		{tags add "trophy_mortar_r_reloading"}
		{delay 1 {tags remove "trophy_mortar_r_reloading"} ("trophy_mortar_r_turn_on")}
;		{if tagged "trophy_r_5remain" {tags remove "trophy_r_5remain"} {tags add "trophy_r_4remain"}
;		else  tagged "trophy_r_4remain" {tags remove "trophy_r_4remain"} {tags add "trophy_r_3remain"}
;		else  tagged "trophy_r_3remain" {tags remove "trophy_r_3remain"} {tags add "trophy_r_2remain"}
		{if tagged "trophy_r_3remain" {tags remove "trophy_r_3remain"} {tags add "trophy_r_2remain"}
		else  tagged "trophy_r_2remain" {tags remove "trophy_r_2remain"} {tags add "trophy_r_1remain"}
		else  tagged "trophy_r_1remain" {tags remove "trophy_r_1remain"} {tags add "trophy_r_empty"}  {delay 10 {tags remove "trophy_r_empty"}}
		else {tags add "trophy_r_5remain"}
		}
	}
	{on "kaz_work" overload
		{if not tagged "no_power"
			  {kill_delay "kaz_delay"}
			  {if work "trophy_mortar_l"
				{if not tagged "trophy_mortar_l_reloading"
					 ("trophy_mortar_l_turn_on")
				else {delay 1 "trophy_mortar_l_reloading" {tags remove "trophy_mortar_l_reloading"} ("trophy_mortar_l_turn_on")}
				}
			  }
			  {if work "trophy_mortar_r"
				{if not tagged "trophy_mortar_r_reloading"
					 ("trophy_mortar_r_turn_on")
				else {delay 1 "trophy_mortar_r_reloading" {tags remove "trophy_mortar_r_reloading"} ("trophy_mortar_r_turn_on")}
				}
			  }
			{delay 3 "kaz_delay"
				{kill_delay "trophy_mortar_l_reloading"}
				{kill_delay "trophy_mortar_r_reloading"}
				("trophy_mortar_r_turn_off")
				("trophy_mortar_l_turn_off")
			}
		}
	}
	{on break
	    {if component "trophy_radar_l1"
		{spawn "tank_die_particle" "Visor_trophy_l1"}
		{tags add "trophy_radar_l1_damaged"}
		{if not tagged "destroyed"
			{damage_report "trophy_radar_l1" "kaz_radar:kaz_radar_damaged"}
			{volumes "trophy_radar_l1" disable bullet contact blast visible obstacle touch select}
			{bone cut "Visor_trophy_l1"}
		}
		{if not work "trophy_radar_l2" {components "trophy_mortar_l" destroy}}
	     else component "trophy_radar_l2"
		{spawn "tank_die_particle" "Visor_trophy_l2"}
		{tags add "trophy_radar_l2_damaged"}
		{if not tagged "destroyed"
			{damage_report "trophy_radar_l2" "kaz_radar:kaz_radar_damaged"}
			{volumes "trophy_radar_l2" disable bullet contact blast visible obstacle touch select}
			{bone cut "Visor_trophy_l2"}
		}
		{if not work "trophy_radar_l1" {components "trophy_mortar_l" destroy}}
	     else component "trophy_radar_r1"
		{spawn "tank_die_particle" "Visor_trophy_r1"}
		{tags add "trophy_radar_r1_damaged"}
		{if not tagged "destroyed"
			{damage_report "trophy_radar_r1" "kaz_radar:kaz_radar_damaged"}
			{volumes "trophy_radar_r1" disable bullet contact blast visible obstacle touch select}
			{bone cut "Visor_trophy_r1"}
		}
		{if not work "trophy_radar_r2" {components "trophy_mortar_r" destroy}}
	     else component "trophy_radar_r2"
		{spawn "tank_die_particle" "Visor_trophy_r2"}
		{tags add "trophy_radar_r2_damaged"}
		{if not tagged "destroyed"
			{damage_report "trophy_radar_r2" "kaz_radar:kaz_radar_damaged"}
			{volumes "trophy_radar_r2" disable bullet contact blast visible obstacle touch select}
			{bone cut "Visor_trophy_r2"}
		}
		{if not work "trophy_radar_r1" {components "trophy_mortar_l" destroy}}
	     else component "trophy_mortar_l"
		{spawn "tank_die_particle" "kaz_l_turr"}
		{tags add "trophy_mortar_l_damaged"}
		{if not tagged "destroyed"
			{damage_report "trophy_mortar_l" "kaz_mortar:kaz_mortar_damaged"}
			{weapon_work "kaz_l" 0}
		}
	     else component "trophy_mortar_r"
		{spawn "tank_die_particle" "kaz_r_turr"}
		{tags add "trophy_mortar_r_damaged"}
		{if not tagged "destroyed"
			{damage_report "trophy_mortar_r" "kaz_mortar:kaz_mortar_damaged"}
			{weapon_work "kaz_r" 0}
		}
	    }
	}
	{on repair
	     {if component "trophy_mortar_l"
		{damage_report "trophy_mortar_l" "kaz_mortar:kaz_mortar_repaired"}
		{weapon_work "kaz_l" 1}
		{tags remove "trophy_mortar_l_damaged"}
	     else component "trophy_mortar_r"
		{damage_report "trophy_mortar_r" "kaz_mortar:kaz_mortar_repaired"}
		{weapon_work "kaz_r" 1}
		{tags remove "trophy_mortar_r_damaged"}
	     }
	}
	{on "kaz_work_on_rpg" overload 
	     {if volume "trophy_left"
		{bullet_detonate}
		{spawn "trophy_rpg_initiator"}
		{tags add "trophy_mortar_l_reloading"}
		("trophy_mortar_l_turn_off")
		{delay 1 {tags remove "trophy_mortar_l_reloading"} ("trophy_mortar_l_turn_on")}
	    else volume "trophy_right"
		{bullet_detonate}
		{spawn "trophy_rpg_initiator"}
		{tags add "trophy_mortar_r_reloading"}
		("trophy_mortar_r_turn_off")
		{delay 1 {tags remove "trophy_mortar_r_reloading"} ("trophy_mortar_r_turn_on")}
	     }
	}
	{on "kaz_work_on_ptur" overload}
	{on "update_power"
		{if tagged "no_power"
			{weapon_work "kaz_l" 0} {weapon_work "kaz_r" 0}
		else
			{if work "trophy_mortar_l" {weapon_work "kaz_l" 1}}
			{if work "trophy_mortar_r" {weapon_work "kaz_r" 1}}		
		}
	}
}
{"trophy_rpg_initiator"
	{on spawn overload
		{volumes enable visible}
		{delay 0.3 {volumes enable visible}}
		{impulse up 0.1 com}
		{gravity 0.3}
		{constrain_velocity 1.5}
		{delay 0.9 {delete}}
	}
	{on "detonate" overload}
	{on contact overload}
	{on ground_hit overload}
	{on pierce overload}
}
{"pg-30_precursor"
	{on spawn overload
		{volumes enable visible}
		{delay 0.3 {volumes enable visible contact}}
		{delay 4 {delete}}
		{impulse forward 50 0.1 up 2 com}
	}
	{on "detonate" overload}
	{on contact overload}
	{on ground_hit overload}
	{on pierce overload}
}
{"trophy_proj_initiator"
	{on spawn overload
		;{impulse up 0.1 com}
		;{gravity 0.3}
		;{constrain_velocity 1.5}
		{physics_work 0}
		{delay 0.5 {delete}}
	}
	{on "detonate" overload}
	{on contact overload}
	{on ground_hit overload}
	{on pierce overload}
}

{"sam"
      {on "update_gun" overload
	     {if work "stabilizer"
		  {if work "gunner_panel"
		   {if not tagged "contusion" 
			{weapon_work "gun" 1}
		   else {weapon_work "gun" 0}}
		  else {weapon_work "gun" 0}}
	     else {weapon_work "gun" 0}}
      }
}
{"cw_secdamage_dir"
	(define "spall_cone2"
		;angle - spall cone angle (25+25 or 25+40)
		;w1p w1r w1d - wave1 power, radius and radius decay (full power on w1r, decays on w1r+w1d)
		{delay 0.01 {spawn "blast_restrictor_afterarmor%angle" dir_velocity no_position		{delay 0.01 
			{fragments c4 %w1p r0 %w1r r1 %w1d position}
			{fragments c4 %w2p r0 %w2r r1 %w2d position}
		}}}
	)
	(define "spall_cone1"
		{delay 0.01 {spawn "blast_restrictor_afterarmor%angle" dir_velocity no_position		{delay 0.01 
			{fragments c4 %w1p r0 %w1r r1 %w1d position}
		}}}
	)
	{on spawn
		{gravity 0.01}
		{delay 0.01
			{if tagged "spall_liner"
				{if tagged "power5"
					("spall_cone2" angle(25) w1p(3.0) w1r(2.5) w1d(0.5) w2p(1.0) w2r(4.0) w2d(2.9))
				else tagged "power4"
					("spall_cone2" angle(25) w1p(2.5) w1r(2.2) w1d(0.5) w2p(0.7) w2r(3.2) w2d(2.9))
				else tagged "power3"
					("spall_cone2" angle(25) w1p(2.0) w1r(2.0) w1d(0.3) w2p(0.5) w2r(2.0) w2d(1.5))
				else tagged "power2"
					("spall_cone1" angle(25) w1p(1.5) w1r(1.7) w1d(0.3))
				else tagged "power1"
					("spall_cone1" angle(25) w1p(0.5) w1r(1.2) w1d(0.3))
				else tagged "hmg" or tagged "bullet"
					("spall_cone1" angle(40) w1p(0.5) w1r(0.4) w1d(0.4))
				else tagged "autocannon"
					("spall_cone1" angle(40) w1p(0.5) w1r(1.2) w1d(1.5))
				else tagged "hesh"
					("spall_cone1" angle(40) w1p(6.5) w1r(2.0) w1d(0.5))
				;else ;default, should not be used because is called somewhy
					("spall_cone2" angle(25) w1p(2.0) w1r(1.5) w1d(0.5) w2p(0.5) w2r(2.0) w2d(1.5))
				}
			else
				{if tagged "power5"
					("spall_cone2" angle(40) w1p(4.0) w1r(2.5) w1d(0.5) w2p(1.5) w2r(5.0) w2d(4.0))
				else tagged "power4"
					("spall_cone2" angle(40) w1p(3.5) w1r(2.2) w1d(0.5) w2p(1.2) w2r(4.2) w2d(3.5))
				else tagged "power3"
					("spall_cone2" angle(40) w1p(3.0) w1r(2.0) w1d(0.3) w2p(1.1) w2r(3.0) w2d(3.0))
				else tagged "power2"
					("spall_cone2" angle(40) w1p(2.5) w1r(1.7) w1d(0.3) w2p(0.8) w2r(2.5) w2d(2.3))
				else tagged "power1"
					("spall_cone2" angle(40) w1p(1.0) w1r(1.2) w1d(0.3) w2p(0.5) w2r(2.0) w2d(1.5))
				else tagged "hmg" or tagged "bullet"
					("spall_cone1" angle(40) w1p(0.5) w1r(0.4) w1d(0.4))
				else tagged "autocannon"
					("spall_cone1" angle(40) w1p(0.5) w1r(1.2) w1d(1.5))
				else tagged "hesh"
					("spall_cone1" angle(40) w1p(6.5) w1r(2.0) w1d(0.5))
				;else ;default, should not be used because is called somewhy
					("spall_cone2" angle(40) w1p(2.5) w1r(1.5) w1d(0.5) w2p(0.8) w2r(3.0) w2d(1.5))
				}
			}
		}
		{delay 0.05 {delete}}
	}
}
;==============================================================

{"auto_dig_in"	;for vehnet installation
	{on "auto_dig_in"
		("spawn")
;		{ani_play "otval"}
		{chassis_work 0} {components "move_indicator" break}
		{delay 1 
			{ani_play "otval" -1}
;			{spawn "dust_shot_big_2" "basis"}
;			{spawn "tank_trench_spawner" "basis" x}
			     {delay 0.5
;				{spawn "spheredust_norm" "basis"}
;				{if terrain_fx "country_road"	{spawn "netting" "basis" x no_normal no_position}
;				else terrain_fx "snow"	{spawn "netting" "basis" x no_normal no_position {tex_morph "win" 0.1}}
;				else terrain_fx "sand"	{spawn "netting" "basis" x no_normal no_position {tex_morph "1" 0.1}}
;				else terrain_fx "grass"	{spawn "netting" "basis" x no_normal no_position }
;				else terrain_fx "ground"	{spawn "netting" "basis" x no_normal no_position }
;				}
				{if terrain_fx "country_road"	{spawn "vehnet" "basis" x no_normal no_position}
				else terrain_fx "snow"	{spawn "vehnet" "basis" x no_normal no_position {tex_morph "win" 0.1}}
				else terrain_fx "sand"	{spawn "vehnet" "basis" x no_normal no_position {tex_morph "1" 0.1}}
				else terrain_fx "grass"	{spawn "vehnet" "basis" x no_normal no_position}
				else terrain_fx "ground"	{spawn "vehnet" "basis" x no_normal no_position}
				}

			     }
			{call "update_moveability"}
		}
	}
}