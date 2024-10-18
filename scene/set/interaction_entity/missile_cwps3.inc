;======================================Описание носителей
{"proj_dummy"
	{on spawn
		{delay 1.0 {tags add "ready"}}
	}
	{on "link_effects"
		{if not props "propfan"
			{delay 0 {with_linked_entity "missile" 
				{add_view	"proj_smoke"		"proj_tail"		"root"}
				{add_view	"proj_smoke30"		"proj_tail30"		"root"}
				{add_view	"proj_smoke20"		"proj_tail20"		"root"}
				{add_view	"proj_smoke10"		"proj_tail10"		"root"}
			}}
		}
		{delay 0.1 {with_linked_entity "missile" {ani_play "move" loop}}}
		{call "link_effects1"}
		{call "manage_effects"}
	}
	{on "manage_effects"
		{call "manage_effects1"}
		{call "launch_procedures"}
	}
	{on "start_guidance_seq"
		{call "launch"}
		{call "chdir_repeater"}
	}
     {on "check_direction"
	;{if velocity 10          {call "detonate"}}

	{impulse forward 0.5 up 0.1 com}	;for better missile colliders
	{gravity 0.1}
	{delay 0.01 {impulse forward -0.1 com}{gravity 0.01}}
	{delay 0.02 {impulse up -0.1 com}{gravity 0.01}}
	{delay 0.03 {impulse forward 0.1 com}{gravity 0.01}}
	{delay 0.04 {impulse up 0.1 com}{gravity 0.01}}
	{delay 0.05 {impulse forward 0.1 com}{gravity 0.01}}
	{delay 0.06 {impulse up -0.1 com}{gravity 0.01}}
	{delay 0.07 {impulse forward -0.1 com}{gravity 0.01}}
	{delay 0.08 {impulse up 0.1 com}{gravity 0.01}}
	{delay 0.09 {impulse up -0.1 com}{gravity 0.01}}
	{delay 0.10 {impulse up 0.1 com}{gravity 0.01}}
	{delay 0.11 {impulse up -0.1 com}{gravity 0.01}}
	{delay 0.12 {impulse up 0.1 com}{gravity 0.01}}
	{delay 0.13 {impulse up -0.1 com}{gravity 0.01}}
	{delay 0.14 {impulse up 0.1 com}{gravity 0.01}}
	{delay 0.15 {impulse up -0.1 com}{gravity 0.01}}

	
	{delay 0.05 
		{call "change_direction"}
	}


     }
     {on "turn_off_ik"
	{ik_enable "stage_hor01" 0}{ik_enable "stage_ver01" 0}
	{ik_enable "stage_hor02" 0}{ik_enable "stage_ver02" 0}
	{ik_enable "stage_hor03" 0}{ik_enable "stage_ver03" 0}
	{ik_enable "stage_hor04" 0}{ik_enable "stage_ver04" 0}
	{ik_enable "stage_hor05" 0}{ik_enable "stage_ver05" 0}
	{ik_enable "stage_hor06" 0}{ik_enable "stage_ver06" 0}
	{ik_enable "stage_hor07" 0}{ik_enable "stage_ver07" 0}
	{ik_enable "stage_hor08" 0}{ik_enable "stage_ver08" 0}
	{ik_enable "stage_hor09" 0}{ik_enable "stage_ver09" 0}
	{ik_enable "stage_hor10" 0}{ik_enable "stage_ver10" 0}
	{ik_enable "stage_hor11" 0}{ik_enable "stage_ver11" 0}
	{ik_enable "stage_hor12" 0}{ik_enable "stage_ver12" 0}
	{ik_enable "stage_hor13" 0}{ik_enable "stage_ver13" 0}
	{ik_enable "stage_hor14" 0}{ik_enable "stage_ver14" 0}
	{ik_enable "stage_hor15" 0}{ik_enable "stage_ver15" 0}
	{ik_enable "stage_hor16" 0}{ik_enable "stage_ver16" 0}
	{ik_enable "stage_hor17" 0}{ik_enable "stage_ver17" 0}
	{ik_enable "stage_hor18" 0}{ik_enable "stage_ver18" 0}
	{ik_enable "stage_hor19" 0}{ik_enable "stage_ver19" 0}
	{ik_enable "stage_hor20" 0}{ik_enable "stage_ver20" 0}
	{ik_enable "stage_hor21" 0}{ik_enable "stage_ver21" 0}
	{ik_enable "stage_hor22" 0}{ik_enable "stage_ver22" 0}
	{ik_enable "stage_hor23" 0}{ik_enable "stage_ver23" 0}
	{ik_enable "stage_hor24" 0}{ik_enable "stage_ver24" 0}
	{ik_enable "stage_hor25" 0}{ik_enable "stage_ver25" 0}
	{ik_enable "stage_hor26" 0}{ik_enable "stage_ver26" 0}
	{ik_enable "stage_hor27" 0}{ik_enable "stage_ver27" 0}
	{ik_enable "stage_hor28" 0}{ik_enable "stage_ver28" 0}
	{ik_enable "stage_hor29" 0}{ik_enable "stage_ver29" 0}
	{ik_enable "stage_hor30" 0}{ik_enable "stage_ver30" 0}
	{ik_enable "stage_hor31" 0}{ik_enable "stage_ver31" 0}
	{ik_enable "stage_hor32" 0}{ik_enable "stage_ver32" 0}
	{ik_enable "stage_hor33" 0}{ik_enable "stage_ver33" 0}
	{ik_enable "stage_hor34" 0}{ik_enable "stage_ver34" 0}
	{ik_enable "stage_hor35" 0}{ik_enable "stage_ver35" 0}
	{ik_enable "stage_hor36" 0}{ik_enable "stage_ver36" 0}
	{ik_enable "stage_hor37" 0}{ik_enable "stage_ver37" 0}
	{ik_enable "stage_hor38" 0}{ik_enable "stage_ver38" 0}
	{ik_enable "stage_hor39" 0}{ik_enable "stage_ver39" 0}
	{ik_enable "stage_hor40" 0}{ik_enable "stage_ver40" 0}
     }

    {on "change_stage"
     
     
     {update_visibility_patch}
        {if tagged "stage_01" {tags remove "stage_01"} {tags add "stage_02"} {ik_enable "stage_hor02" 1}{ik_enable "stage_ver02" 1}{ik_enable "stage_hor01" 0}{ik_enable "stage_ver01" 0}{tags add "start"}
	else tagged "stage_02" {tags remove "stage_02"} {tags add "stage_03"} {ik_enable "stage_hor03" 1}{ik_enable "stage_ver03" 1}{ik_enable "stage_hor02" 0}{ik_enable "stage_ver02" 0}
	else tagged "stage_03" {tags remove "stage_03"} {tags add "stage_04"} {ik_enable "stage_hor04" 1}{ik_enable "stage_ver04" 1}{ik_enable "stage_hor03" 0}{ik_enable "stage_ver03" 0}
	else tagged "stage_04" {tags remove "stage_04"} {tags add "stage_05"} {ik_enable "stage_hor05" 1}{ik_enable "stage_ver05" 1}{ik_enable "stage_hor04" 0}{ik_enable "stage_ver04" 0}
	else tagged "stage_05" {tags remove "stage_05"} {tags add "stage_06"} {ik_enable "stage_hor06" 1}{ik_enable "stage_ver06" 1}{ik_enable "stage_hor05" 0}{ik_enable "stage_ver05" 0}
	else tagged "stage_06" {tags remove "stage_06"} {tags add "stage_07"} {ik_enable "stage_hor07" 1}{ik_enable "stage_ver07" 1}{ik_enable "stage_hor06" 0}{ik_enable "stage_ver06" 0}
	else tagged "stage_07" {tags remove "stage_07"} {tags add "stage_08"} {ik_enable "stage_hor08" 1}{ik_enable "stage_ver08" 1}{ik_enable "stage_hor07" 0}{ik_enable "stage_ver07" 0}
	else tagged "stage_08" {tags remove "stage_08"} {tags add "stage_09"} {ik_enable "stage_hor09" 1}{ik_enable "stage_ver09" 1}{ik_enable "stage_hor08" 0}{ik_enable "stage_ver08" 0}
	else tagged "stage_09" {tags remove "stage_09"} {tags add "stage_10"}  {ik_enable "stage_hor10" 1}{ik_enable "stage_ver10" 1}{ik_enable "stage_hor09" 0}{ik_enable "stage_ver09" 0}{tags add "50m_fly"}
	else tagged "stage_10" {tags remove "stage_10"} {tags add "stage_11"} {ik_enable "stage_hor11" 1}{ik_enable "stage_ver11" 1}{ik_enable "stage_hor10" 0}{ik_enable "stage_ver10" 0}
	else tagged "stage_11" {tags remove "stage_11"} {tags add "stage_12"} {ik_enable "stage_hor12" 1}{ik_enable "stage_ver12" 1}{ik_enable "stage_hor11" 0}{ik_enable "stage_ver11" 0}
	else tagged "stage_12" {tags remove "stage_12"} {tags add "stage_13"} {ik_enable "stage_hor13" 1}{ik_enable "stage_ver13" 1}{ik_enable "stage_hor12" 0}{ik_enable "stage_ver12" 0}
	else tagged "stage_13" {tags remove "stage_13"} {tags add "stage_14"} {ik_enable "stage_hor14" 1}{ik_enable "stage_ver14" 1}{ik_enable "stage_hor13" 0}{ik_enable "stage_ver13" 0}
	else tagged "stage_14" {tags remove "stage_14"} {tags add "stage_15"} {ik_enable "stage_hor15" 1}{ik_enable "stage_ver15" 1}{ik_enable "stage_hor14" 0}{ik_enable "stage_ver14" 0}
	else tagged "stage_15" {tags remove "stage_15"} {tags add "stage_16"} {ik_enable "stage_hor16" 1}{ik_enable "stage_ver16" 1}{ik_enable "stage_hor15" 0}{ik_enable "stage_ver15" 0}
	else tagged "stage_16" {tags remove "stage_16"} {tags add "stage_17"} {ik_enable "stage_hor17" 1}{ik_enable "stage_ver17" 1}{ik_enable "stage_hor16" 0}{ik_enable "stage_ver16" 0}
	else tagged "stage_17" {tags remove "stage_17"} {tags add "stage_18"} {ik_enable "stage_hor18" 1}{ik_enable "stage_ver18" 1}{ik_enable "stage_hor17" 0}{ik_enable "stage_ver17" 0}
	else tagged "stage_18" {tags remove "stage_18"} {tags add "stage_19"} {ik_enable "stage_hor19" 1}{ik_enable "stage_ver19" 1}{ik_enable "stage_hor18" 0}{ik_enable "stage_ver18" 0}
	else tagged "stage_19" {tags remove "stage_19"} {tags add "stage_20"} {ik_enable "stage_hor20" 1}{ik_enable "stage_ver20" 1}{ik_enable "stage_hor19" 0}{ik_enable "stage_ver19" 0}{tags add "100m_fly"}
	else tagged "stage_20" {tags remove "stage_20"} {tags add "stage_21"} {ik_enable "stage_hor21" 1}{ik_enable "stage_ver21" 1}{ik_enable "stage_hor20" 0}{ik_enable "stage_ver20" 0}
	else tagged "stage_21" {tags remove "stage_21"} {tags add "stage_22"} {ik_enable "stage_hor22" 1}{ik_enable "stage_ver22" 1}{ik_enable "stage_hor21" 0}{ik_enable "stage_ver21" 0}
	else tagged "stage_22" {tags remove "stage_22"} {tags add "stage_23"} {ik_enable "stage_hor23" 1}{ik_enable "stage_ver23" 1}{ik_enable "stage_hor22" 0}{ik_enable "stage_ver22" 0}
	else tagged "stage_23" {tags remove "stage_23"} {tags add "stage_24"} {ik_enable "stage_hor24" 1}{ik_enable "stage_ver24" 1}{ik_enable "stage_hor23" 0}{ik_enable "stage_ver23" 0}
	else tagged "stage_24" {tags remove "stage_24"} {tags add "stage_25"} {ik_enable "stage_hor25" 1}{ik_enable "stage_ver25" 1}{ik_enable "stage_hor24" 0}{ik_enable "stage_ver24" 0}
	else tagged "stage_25" {tags remove "stage_25"} {tags add "stage_26"} {ik_enable "stage_hor26" 1}{ik_enable "stage_ver26" 1}{ik_enable "stage_hor25" 0}{ik_enable "stage_ver25" 0}
	else tagged "stage_26" {tags remove "stage_26"} {tags add "stage_27"} {ik_enable "stage_hor27" 1}{ik_enable "stage_ver27" 1}{ik_enable "stage_hor26" 0}{ik_enable "stage_ver26" 0}
	else tagged "stage_27" {tags remove "stage_27"} {tags add "stage_28"} {ik_enable "stage_hor28" 1}{ik_enable "stage_ver28" 1}{ik_enable "stage_hor27" 0}{ik_enable "stage_ver27" 0}
	else tagged "stage_28" {tags remove "stage_28"} {tags add "stage_29"} {ik_enable "stage_hor29" 1}{ik_enable "stage_ver29" 1}{ik_enable "stage_hor28" 0}{ik_enable "stage_ver28" 0}
	else tagged "stage_29" {tags remove "stage_29"} {tags add "stage_30"} {ik_enable "stage_hor30" 1}{ik_enable "stage_ver30" 1}{ik_enable "stage_hor29" 0}{ik_enable "stage_ver29" 0}{tags add "150m_fly"}
	else tagged "stage_30" {tags remove "stage_30"} {tags add "stage_31"} {ik_enable "stage_hor31" 1}{ik_enable "stage_ver31" 1}{ik_enable "stage_hor30" 0}{ik_enable "stage_ver30" 0}
	else tagged "stage_31" {tags remove "stage_31"} {tags add "stage_32"} {ik_enable "stage_hor32" 1}{ik_enable "stage_ver32" 1}{ik_enable "stage_hor31" 0}{ik_enable "stage_ver31" 0}
	else tagged "stage_32" {tags remove "stage_32"} {tags add "stage_33"} {ik_enable "stage_hor33" 1}{ik_enable "stage_ver33" 1}{ik_enable "stage_hor32" 0}{ik_enable "stage_ver32" 0}
	else tagged "stage_33" {tags remove "stage_33"} {tags add "stage_34"} {ik_enable "stage_hor34" 1}{ik_enable "stage_ver34" 1}{ik_enable "stage_hor33" 0}{ik_enable "stage_ver33" 0}
	else tagged "stage_34" {tags remove "stage_34"} {tags add "stage_35"} {ik_enable "stage_hor35" 1}{ik_enable "stage_ver35" 1}{ik_enable "stage_hor34" 0}{ik_enable "stage_ver34" 0}
	else tagged "stage_35" {tags remove "stage_35"} {tags add "stage_36"} {ik_enable "stage_hor36" 1}{ik_enable "stage_ver36" 1}{ik_enable "stage_hor35" 0}{ik_enable "stage_ver35" 0}
	else tagged "stage_36" {tags remove "stage_36"} {tags add "stage_37"} {ik_enable "stage_hor37" 1}{ik_enable "stage_ver37" 1}{ik_enable "stage_hor36" 0}{ik_enable "stage_ver36" 0}
	else tagged "stage_37" {tags remove "stage_37"} {tags add "stage_38"} {ik_enable "stage_hor38" 1}{ik_enable "stage_ver38" 1}{ik_enable "stage_hor37" 0}{ik_enable "stage_ver37" 0}
	else tagged "stage_38" {tags remove "stage_38"} {tags add "stage_39"} {ik_enable "stage_hor39" 1}{ik_enable "stage_ver39" 1}{ik_enable "stage_hor38" 0}{ik_enable "stage_ver38" 0}
	else tagged "stage_39" {tags remove "stage_39"} {tags add "stage_40"}  {ik_enable "stage_hor40" 1}{ik_enable "stage_ver40" 1}{ik_enable "stage_hor39" 0}{ik_enable "stage_ver39" 0}{tags add "200m_fly"}
	else tagged "stage_40" 
		{tags remove "stage_40"} 
		{if tagged "cwps_extended_range2" 
			{call "spawn_presecond_stage"}
		else tagged "cwps_extended_range"
			{call "spawn_second_stage"}
		else 
			{call "detonate"}
		}
        }
	{call "check_altitude"}
	{if not altitude 15
		{delay 0.05 {call "check_altitude"} }
		{delay 0.1 {call "check_altitude"} }
	}
    }
	{on "check_altitude"
		{with_linked_entity "missile"
			{if not altitude 0.1
				{if not tagged "underwater_launch"
					;{spawn "proj_point_dummy" "root"}
					{spawn "proj_deleter" "root"
					{delay 0.2 {delete}}
					}	;вызывает вылет изредка
				}
			else not altitude 10
				{if tagged "underwater_launch"
					{spawn "ex_water_big"}
				}
				{tags remove "underwater_launch"}
				{view pause "proj_tail10"}
				{view pause "proj_tail20"}
				{view pause "proj_tail30"}
				{view pause "proj_tail"}
			else not altitude 20
				{tags remove "underwater_launch"}
				{view start "proj_tail10"}
				{view pause "proj_tail20"}
				{view pause "proj_tail30"}
				{view pause "proj_tail"}
			else not altitude 30
				{tags remove "underwater_launch"}
				{view pause "proj_tail10"}
				{view start "proj_tail20"}
				{view pause "proj_tail30"}
				{view pause "proj_tail"}
			else not altitude 40
				{tags remove "underwater_launch"}
				{view pause "proj_tail10"}
				{view pause "proj_tail20"}
				{view start "proj_tail30"}
				{view pause "proj_tail"}
			else
				{tags remove "underwater_launch"}
				{view pause "proj_tail10"}
				{view pause "proj_tail20"}
				{view pause "proj_tail30"}
				{view start "proj_tail"}
			}
		}
	}
     {on overlap end
     }

     {on "detonate"
       {if not flag "detonate"
		{set "detonate" 1}
		{call "spawn_missile"}
		{with_linked_entity "missile"
			{delete}
		}
		{delete}
       }
     }

     {on "destroyed_by_kaz"
       {if not flag "detonate"
		{set "detonate" 1}
;		{with_linked_entity "missile"	;линкованные импакторы больше не имеют stuff
;			{stuff_detonate}
;		}
		{call "spawn_missile_ground"}
		{with_linked_entity "missile"
			{delete}
		}
		{delete}
       }
     }
     {on "destroyed_by_ground"
       {if not flag "detonate"
		{set "detonate" 1}
		{call "spawn_missile_ground"}
		{with_linked_entity "missile"
			{delete}
		}
		{delete}
       }
     }

     {on "spawn_missile"
	 {weapon_work "targeting_sys_anti_jamming" 0}
     }
     {on "spawn_missile_ground"
     }
	 
	{on "check_no_signal"
		{delay 0.5 {if tagged "no_power" {tags remove "guided"}  {weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}}}
	}
     {on contact
     	{if effector "small wood" {with_effector {call "break"}{with_effector}}
		else effector "proj_deleter"
	;;		{delete}	;to hide when ground hit
	;		{volumes disable all}
	;		{set "detonate" 1}
			{call "destroyed_by_ground"}
		else effector "proj_point"
			{call "detonate"}	;to exclude accidental ricoshetes with small vehicles
		else effector "smoke_cloud"
			{if tagged "smoke_vulnerable" {if tagged "guided"  {tags remove "guided"}     {weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}      }}
		else effector "kaz"
		else effector "trophy_proj_initiator" {call "destroyed_by_kaz"} {with_effector {volumes disable contact}{with_effector}}
		else effector "targetable_missile"
			{call "detonate"}
		else effector "targetable_impactor"
			{call "detonate"}
		else volume "second_det"
			{if effector "vehicle" {call "detonate"}
			else {volumes "second_det" disable contact} {delay 0.1 {volumes "second_det" enable contact}}}
		else effector "proj_dummy"
;			{call "detonate"}
			{if volume "proximity"	{volumes "proximity" disable contact} {delay 0.1 {volumes "proximity" enable contact}}
			else {call "detonate"}}
		else effector "projectile_impactor"
			{if volume "proximity"	{volumes "proximity" disable contact} {delay 0.1 {volumes "proximity" enable contact}}
			else {call "detonate"}}
		else volume "proximity"
			{if relation "enemy" or relation "neutral" {call "detonate"}
			else {volumes "proximity" disable contact} {delay 1 {volumes "proximity" enable contact}}
			}
		else 
			{call "detonate"}
		}
     }
     {on ground_hit overload
		{call "detonate"}
     }
     {on pierce overload
          {if not stuff "proj_pointer"
			{call "detonate"}
           }
     }
     {on blast_hit
	{call "detonate"}
     }
     {on bullet_hit overload
		{if stuff "trophy" {call "destroyed_by_kaz"}
		else stuff "radiowave" {with_linked_entity "missile" {call "missile_lock"}}
		else stuff "anti_smallmissile" {with_linked_entity "missile" {call "missile_lock_long"}}
		}
     }
 }
 
 
(define "speed_fast"
	;variable speed
	{on "chdir_repeater" overload
		{delay (/	0.16	%coeff) {call "check_direction"}}
		{delay (/	0.32	%coeff) {call "check_direction"}}
		{delay (/	0.48	%coeff) {call "check_direction"}}
		{delay (/	0.64	%coeff) {call "check_direction"}}
		{delay (/	0.8	%coeff) {call "check_direction"}}
		{delay (/	0.96	%coeff) {call "check_direction"}}
		{delay (/	1.12	%coeff) {call "check_direction"}}
		{delay (/	1.28	%coeff) {call "check_direction"}}
		{delay (/	1.44	%coeff) {call "check_direction"}}
		{delay (/	1.6	%coeff) {call "check_direction"}}
		{delay (/	1.76	%coeff) {call "check_direction"}}
		{delay (/	1.92	%coeff) {call "check_direction"}}
		{delay (/	2.08	%coeff) {call "check_direction"}}
		{delay (/	2.24	%coeff) {call "check_direction"}}
		{delay (/	2.4	%coeff) {call "check_direction"}}
		{delay (/	2.56	%coeff) {call "check_direction"}}
		{delay (/	2.72	%coeff) {call "check_direction"}}
		{delay (/	2.88	%coeff) {call "check_direction"}}
		{delay (/	3.04	%coeff) {call "check_direction"}}
		{delay (/	3.2	%coeff) {call "check_direction"}}
		{delay (/	3.36	%coeff) {call "check_direction"}}
		{delay (/	3.52	%coeff) {call "check_direction"}}
		{delay (/	3.68	%coeff) {call "check_direction"}}
		{delay (/	3.84	%coeff) {call "check_direction"}}
		{delay (/	4	%coeff) {call "check_direction"}}
		{delay (/	4.16	%coeff) {call "check_direction"}}
		{delay (/	4.32	%coeff) {call "check_direction"}}
		{delay (/	4.48	%coeff) {call "check_direction"}}
		{delay (/	4.64	%coeff) {call "check_direction"}}
		{delay (/	4.8	%coeff) {call "check_direction"}}
		{delay (/	4.96	%coeff) {call "check_direction"}}
		{delay (/	5.12	%coeff) {call "check_direction"}}
		{delay (/	5.28	%coeff) {call "check_direction"}}
		{delay (/	5.44	%coeff) {call "check_direction"}}
		{delay (/	5.6	%coeff) {call "check_direction"}}
		{delay (/	5.76	%coeff) {call "check_direction"}}
		{delay (/	5.92	%coeff) {call "check_direction"}}
		{delay (/	6.08	%coeff) {call "check_direction"}}
		{delay (/	6.24	%coeff) {call "check_direction"}}
		{delay (/	6.4	%coeff) {call "check_direction"}}

	}
	{on "launch" overload {ani_play "center_veryfast" (* 0.75 %coeff)}	}
)
(define "speed_normal"
	;variable speed
	{on "chdir_repeater" overload
		{delay (/	0.213	%coeff) {call "check_direction"}}
		{delay (/	0.426	%coeff) {call "check_direction"}}
		{delay (/	0.639	%coeff) {call "check_direction"}}
		{delay (/	0.852	%coeff) {call "check_direction"}}
		{delay (/	1.065	%coeff) {call "check_direction"}}
		{delay (/	1.278	%coeff) {call "check_direction"}}
		{delay (/	1.491	%coeff) {call "check_direction"}}
		{delay (/	1.704	%coeff) {call "check_direction"}}
		{delay (/	1.917	%coeff) {call "check_direction"}}
		{delay (/	2.13	%coeff) {call "check_direction"}}
		{delay (/	2.343	%coeff) {call "check_direction"}}
		{delay (/	2.556	%coeff) {call "check_direction"}}
		{delay (/	2.769	%coeff) {call "check_direction"}}
		{delay (/	2.982	%coeff) {call "check_direction"}}
		{delay (/	3.195	%coeff) {call "check_direction"}}
		{delay (/	3.408	%coeff) {call "check_direction"}}
		{delay (/	3.621	%coeff) {call "check_direction"}}
		{delay (/	3.834	%coeff) {call "check_direction"}}
		{delay (/	4.047	%coeff) {call "check_direction"}}
		{delay (/	4.26	%coeff) {call "check_direction"}}
		{delay (/	4.473	%coeff) {call "check_direction"}}
		{delay (/	4.686	%coeff) {call "check_direction"}}
		{delay (/	4.899	%coeff) {call "check_direction"}}
		{delay (/	5.112	%coeff) {call "check_direction"}}
		{delay (/	5.325	%coeff) {call "check_direction"}}
		{delay (/	5.538	%coeff) {call "check_direction"}}
		{delay (/	5.751	%coeff) {call "check_direction"}}
		{delay (/	5.964	%coeff) {call "check_direction"}}
		{delay (/	6.177	%coeff) {call "check_direction"}}
		{delay (/	6.39	%coeff) {call "check_direction"}}
		{delay (/	6.603	%coeff) {call "check_direction"}}
		{delay (/	6.816	%coeff) {call "check_direction"}}
		{delay (/	7.029	%coeff) {call "check_direction"}}
		{delay (/	7.242	%coeff) {call "check_direction"}}
		{delay (/	7.455	%coeff) {call "check_direction"}}
		{delay (/	7.668	%coeff) {call "check_direction"}}
		{delay (/	7.881	%coeff) {call "check_direction"}}
		{delay (/	8.094	%coeff) {call "check_direction"}}
		{delay (/	8.307	%coeff) {call "check_direction"}}
		{delay (/	8.52	%coeff) {call "check_direction"}}

	}
	{on "launch" overload {ani_play "center_fast" (* 0.5625 %coeff)}	}
)
(define "speed_slow"
	;variable speed
	{on "chdir_repeater" overload
		{delay (/	0.24	%coeff) {call "check_direction"}}
		{delay (/	0.48	%coeff) {call "check_direction"}}
		{delay (/	0.72	%coeff) {call "check_direction"}}
		{delay (/	0.96	%coeff) {call "check_direction"}}
		{delay (/	1.2	%coeff) {call "check_direction"}}
		{delay (/	1.44	%coeff) {call "check_direction"}}
		{delay (/	1.68	%coeff) {call "check_direction"}}
		{delay (/	1.92	%coeff) {call "check_direction"}}
		{delay (/	2.16	%coeff) {call "check_direction"}}
		{delay (/	2.4	%coeff) {call "check_direction"}}
		{delay (/	2.64	%coeff) {call "check_direction"}}
		{delay (/	2.88	%coeff) {call "check_direction"}}
		{delay (/	3.12	%coeff) {call "check_direction"}}
		{delay (/	3.36	%coeff) {call "check_direction"}}
		{delay (/	3.6	%coeff) {call "check_direction"}}
		{delay (/	3.84	%coeff) {call "check_direction"}}
		{delay (/	4.08	%coeff) {call "check_direction"}}
		{delay (/	4.32	%coeff) {call "check_direction"}}
		{delay (/	4.56	%coeff) {call "check_direction"}}
		{delay (/	4.8	%coeff) {call "check_direction"}}
		{delay (/	5.04	%coeff) {call "check_direction"}}
		{delay (/	5.28	%coeff) {call "check_direction"}}
		{delay (/	5.52	%coeff) {call "check_direction"}}
		{delay (/	5.76	%coeff) {call "check_direction"}}
		{delay (/	6	%coeff) {call "check_direction"}}
		{delay (/	6.24	%coeff) {call "check_direction"}}
		{delay (/	6.48	%coeff) {call "check_direction"}}
		{delay (/	6.72	%coeff) {call "check_direction"}}
		{delay (/	6.96	%coeff) {call "check_direction"}}
		{delay (/	7.2	%coeff) {call "check_direction"}}
		{delay (/	7.44	%coeff) {call "check_direction"}}
		{delay (/	7.68	%coeff) {call "check_direction"}}
		{delay (/	7.92	%coeff) {call "check_direction"}}
		{delay (/	8.16	%coeff) {call "check_direction"}}
		{delay (/	8.4	%coeff) {call "check_direction"}}
		{delay (/	8.64	%coeff) {call "check_direction"}}
		{delay (/	8.88	%coeff) {call "check_direction"}}
		{delay (/	9.12	%coeff) {call "check_direction"}}
		{delay (/	9.36	%coeff) {call "check_direction"}}
		{delay (/	9.6	%coeff) {call "check_direction"}}
	}
	{on "launch" overload {ani_play "center" (* 0.5 %coeff)}}
)
(define "antislip"
;	{on "check_altitude"
;		{with_linked_entity "missile"
;			{if not altitude 1.0
;				{if not tagged "underwater_launch"
;					{spawn "proj_point_dummy" "root"}
;					{spawn "proj_deleter" "root"
;					{delay 0.1 {delete}}
;					}	;вызывает вылет изредка
;				}
;			}	
;		}
;	}	
)
{"proj_dummy fast"
	{on spawn
	     {call "turn_off_ik"}
	     {tags add "guided"}
		 {call "check_no_signal"}
	     {volumes "missile" disable contact blast}
	     {volumes "target" disable contact blast}
	     {volumes "target1" disable contact blast}
	     {delay 0.1 
		     {volumes "missile" enable contact}
		     {volumes "target" enable bullet blast}
		     {volumes "target1" enable bullet blast}
	     }
	     {delay 1 
		     {volumes "proximity" enable contact}
	     }
;	     {delay 0.1
	     {delay 0
			{call "link_effects"}
			{impulse forward 2 com}{gravity 0.01}
			{tags add "stage_01"} {ik_enable "stage_hor01" 1}{ik_enable "stage_ver01" 1}
		;variable speed
			{call "start_guidance_seq"}
	     }
	}


	(define "try_launch_stage"
	       tagged "stage_%0"
		{if not tagged "guided"
		       {if rand 0.3
			("turn_to" args %0 left hor)
		        else rand 0.7
			("turn_to" args %0 right hor)
		        }
		       {if rand 0.3
			("turn_to" args %0 top ver)
		        else rand 0.7
			("turn_to" args %0 bottom ver)
		        }
		}
	)
	
	("speed_fast" coeff(1))

	(define "turn_to"
	        {if not flag "%2_dir_checked"
		{ani_play "stage_%2%0_%1" 0.35}
	        }
	)
	
     {on "change_direction"
	{if ("try_launch_stage" args 01)
	else ("try_launch_stage" args 02)
	else ("try_launch_stage" args 03)
	else ("try_launch_stage" args 04)
	else ("try_launch_stage" args 05)
	else ("try_launch_stage" args 06)
	else ("try_launch_stage" args 07)
	else ("try_launch_stage" args 08)
	else ("try_launch_stage" args 09)
	else ("try_launch_stage" args 10)
	else ("try_launch_stage" args 11)
	else ("try_launch_stage" args 12)
	else ("try_launch_stage" args 13)
	else ("try_launch_stage" args 14)
	else ("try_launch_stage" args 15)
	else ("try_launch_stage" args 16)
	else ("try_launch_stage" args 17)
	else ("try_launch_stage" args 18)
	else ("try_launch_stage" args 19)
	else ("try_launch_stage" args 20)
	else ("try_launch_stage" args 21)
	else ("try_launch_stage" args 22)
	else ("try_launch_stage" args 23)
	else ("try_launch_stage" args 24)
	else ("try_launch_stage" args 25)
	else ("try_launch_stage" args 26)
	else ("try_launch_stage" args 27)
	else ("try_launch_stage" args 28)
	else ("try_launch_stage" args 29)
	else ("try_launch_stage" args 30)
	else ("try_launch_stage" args 31)
	else ("try_launch_stage" args 32)
	else ("try_launch_stage" args 33)
	else ("try_launch_stage" args 34)
	else ("try_launch_stage" args 35)
	else ("try_launch_stage" args 36)
	else ("try_launch_stage" args 37)
	else ("try_launch_stage" args 38)
	else ("try_launch_stage" args 39)
	else ("try_launch_stage" args 40)
	}
	{set "left_overlap" 0}
	{set "right_overlap" 0}
	{set "top_overlap" 0}
	{set "bottom_overlap" 0}
	{set "hor_dir_checked" 0}
	{set "ver_dir_checked" 0}
	{call "change_stage"}
     }
}

{"proj_dummy normal"
	{on spawn
	     {call "turn_off_ik"}
	     {tags add "guided"}
		 {call "check_no_signal"}
	     {volumes "missile" disable contact blast}
	     {volumes "target" disable contact blast}
	     {volumes "target1" disable contact blast}
	     {delay 0.1 
		     {volumes "missile" enable contact}
		     {volumes "target" enable bullet blast}
		     {volumes "target1" enable bullet blast}
	     }
	     {delay 1 
		     {volumes "proximity" enable contact}
	     }
;	     {delay 0.1
	     {delay 0
			{call "link_effects"}
			{impulse forward 2 com}{gravity 0.01}
			{tags add "stage_01"} {ik_enable "stage_hor01" 1}{ik_enable "stage_ver01" 1}
		;variable speed
			{call "start_guidance_seq"}
	     }
	}

	(define "try_launch_stage"
	       tagged "stage_%0"
		{if not tagged "guided"
		       {if rand 0.3
			("turn_to" args %0 left hor)
		        else rand 0.7
			("turn_to" args %0 right hor)
		        }
		       {if rand 0.3
			("turn_to" args %0 top ver)
		        else rand 0.7
			("turn_to" args %0 bottom ver)
		        }
		}
	)
	("speed_normal" coeff(1))

	(define "turn_to"
	        {if not flag "%2_dir_checked"
		{ani_play "stage_%2%0_%1" 0.1}
	        }
	)
	
     {on "change_direction"
	{if ("try_launch_stage" args 01)
	else ("try_launch_stage" args 02)
	else ("try_launch_stage" args 03)
	else ("try_launch_stage" args 04)
	else ("try_launch_stage" args 05)
	else ("try_launch_stage" args 06)
	else ("try_launch_stage" args 07)
	else ("try_launch_stage" args 08)
	else ("try_launch_stage" args 09)
	else ("try_launch_stage" args 10)
	else ("try_launch_stage" args 11)
	else ("try_launch_stage" args 12)
	else ("try_launch_stage" args 13)
	else ("try_launch_stage" args 14)
	else ("try_launch_stage" args 15)
	else ("try_launch_stage" args 16)
	else ("try_launch_stage" args 17)
	else ("try_launch_stage" args 18)
	else ("try_launch_stage" args 19)
	else ("try_launch_stage" args 20)
	else ("try_launch_stage" args 21)
	else ("try_launch_stage" args 22)
	else ("try_launch_stage" args 23)
	else ("try_launch_stage" args 24)
	else ("try_launch_stage" args 25)
	else ("try_launch_stage" args 26)
	else ("try_launch_stage" args 27)
	else ("try_launch_stage" args 28)
	else ("try_launch_stage" args 29)
	else ("try_launch_stage" args 30)
	else ("try_launch_stage" args 31)
	else ("try_launch_stage" args 32)
	else ("try_launch_stage" args 33)
	else ("try_launch_stage" args 34)
	else ("try_launch_stage" args 35)
	else ("try_launch_stage" args 36)
	else ("try_launch_stage" args 37)
	else ("try_launch_stage" args 38)
	else ("try_launch_stage" args 39)
	else ("try_launch_stage" args 40)
	}
	{set "left_overlap" 0}
	{set "right_overlap" 0}
	{set "top_overlap" 0}
	{set "bottom_overlap" 0}
	{set "hor_dir_checked" 0}
	{set "ver_dir_checked" 0}
	{call "change_stage"}
     }
}
{"proj_dummy slow"
	{on spawn
	     {call "turn_off_ik"}
	     {tags add "guided"}
		 {call "check_no_signal"}
	     {volumes "missile" disable contact blast}
	     {volumes "target" disable contact blast}
	     {volumes "target1" disable contact blast}
	     {delay 0.4 
		     {volumes "missile" enable contact}
		     {volumes "target" enable bullet blast}
		     {volumes "target1" enable bullet blast}
	     }
	     {delay 1 
		     {volumes "proximity" enable contact}
	     }
;	     {delay 0.1
	     {delay 0
			{call "link_effects"}
			{impulse forward 2 com}{gravity 0.01}
			{tags add "stage_01"} {ik_enable "stage_hor01" 1}{ik_enable "stage_ver01" 1}
		;variable speed
			{call "start_guidance_seq"}
		
	     }
	}


	(define "try_launch_stage"
	       tagged "stage_%0"
		{if not tagged "guided"
		       {if rand 0.3
			("turn_to" args %0 left hor)
		        else rand 0.7
			("turn_to" args %0 right hor)
		        }
		       {if rand 0.3
			("turn_to" args %0 top ver)
		        else rand 0.7
			("turn_to" args %0 bottom ver)
		        }
		}
	)
	("speed_slow" coeff(1))

	(define "turn_to"
	        {if not flag "%2_dir_checked"
		{ani_play "stage_%2%0_%1" 0.2}
	        }
	)

	
     {on "change_direction"
	{if ("try_launch_stage" args 01)
	else ("try_launch_stage" args 02)
	else ("try_launch_stage" args 03)
	else ("try_launch_stage" args 04)
	else ("try_launch_stage" args 05)
	else ("try_launch_stage" args 06)
	else ("try_launch_stage" args 07)
	else ("try_launch_stage" args 08)
	else ("try_launch_stage" args 09)
	else ("try_launch_stage" args 10)
	else ("try_launch_stage" args 11)
	else ("try_launch_stage" args 12)
	else ("try_launch_stage" args 13)
	else ("try_launch_stage" args 14)
	else ("try_launch_stage" args 15)
	else ("try_launch_stage" args 16)
	else ("try_launch_stage" args 17)
	else ("try_launch_stage" args 18)
	else ("try_launch_stage" args 19)
	else ("try_launch_stage" args 20)
	else ("try_launch_stage" args 21)
	else ("try_launch_stage" args 22)
	else ("try_launch_stage" args 23)
	else ("try_launch_stage" args 24)
	else ("try_launch_stage" args 25)
	else ("try_launch_stage" args 26)
	else ("try_launch_stage" args 27)
	else ("try_launch_stage" args 28)
	else ("try_launch_stage" args 29)
	else ("try_launch_stage" args 30)
	else ("try_launch_stage" args 31)
	else ("try_launch_stage" args 32)
	else ("try_launch_stage" args 33)
	else ("try_launch_stage" args 34)
	else ("try_launch_stage" args 35)
	else ("try_launch_stage" args 36)
	else ("try_launch_stage" args 37)
	else ("try_launch_stage" args 38)
	else ("try_launch_stage" args 39)
	else ("try_launch_stage" args 40)
	}
	{set "left_overlap" 0}
	{set "right_overlap" 0}
	{set "top_overlap" 0}
	{set "bottom_overlap" 0}
	{set "hor_dir_checked" 0}
	{set "ver_dir_checked" 0}
	{call "change_stage"}
     }
}


;=======================
{"proj_restrictor"
	{on spawn {delay 0.1 {delete}}}
	{on bullet_hit {delete}}
}
{"rpg_restrictor"
	{on spawn {delay 0.2 {delete}}}
	{on bullet_hit {delete}}
}
{"projectile_impactor"
	{on spawn
	    ;{volumes enable contact contact_ground}
		{delay 0.1
			{call "link_sound"}
		}
	}
	{on "link_sound"
		{if linked
			{link_sound "fly"	"vehicle/engine_cw/missile/missileengine"}
			{play_sound "fly" 1}
			{tags add "cwps_missile_minimap"}
		}
	}
	{on "detonate"
	    {if altitude 0
;		 {spawn "proj_restrictor" "root" x}
		 {stuff_detonate}
			{manual_shot}

		  else   			  
		    ;{physics_work 0}
				{gravity 0}
            ;{delay 0.01 
			;{physics_work 1}
			{impulse up 2.0}
			{call "underground_detonate"}
			;}
			
			
		}
	}
	{on "underground_detonate"
	    {if altitude 0
		 ;{spawn "proj_restrictor" "root" x}
;		 {stuff_detonate}
		{manual_shot}
		{delay 0.01 {stuff_detonate}}
		  else   		  
		    {impulse up 2.0}
			{delay 0.01 {call "underground_detonate"}}
			
		}
	}
	{on "delete" {delete}}
	{on contact 
		{call "detonate"}
	}
	{on ground_hit
		{call "detonate"}
	}
	{on pierce 
		{if not stuff "proj_pointer"
			{call "detonate"}
		}
	}
	{on blast
		{if min_energy 0.3
			{call "detonate"}
		}
	}
}

{"switchblade300_impactor"
    {on "detonate" overload
		 {volumes disable all}
		 {spawn "blast_restrictor_directional" "root" x}
		 {stuff_detonate}
	}
}
{"krasnopol_impactor"
    {on spawn
		{volumes enable contact_ground}
	}
	{on ground_hit
	    {stuff_detonate}
	}
	{on contact
	    {stuff_detonate}
	}
}
{"projectile_impactor silent"
	{on "link_sound" overload
		{if linked
			{tags add "cwps_missile_minimap"}
		}
	}
}
{"projectile_impactor propfan"
	{on "link_sound" overload
		{if linked
			{link_sound "fly"	"vehicle/airborne/small_UAV/small_UAV_work"}
			{play_sound "fly" 1}
			{tags add "cwps_missile_minimap"}
		}
	}
}
{"shahed136_base_impactor_link"
	{on "link_sound" overload
		{if linked
			{link_sound "fly"	"vehicle/airborne/small_uav/shahed136_engine"}
			{play_sound "fly" 1}
			{tags add "cwps_missile_minimap"}
		}
	}
}
{"projectile_impactor  efp_core"
	{on spawn
		{delay 3 {stuff_detonate}} ;если сам не исчез
	}
	{on contact overload
		{if effector "vehicle"
		   {if not flag "detonate"
			{set "detonate" 1}{call "spawn_cm_jet"} {delay 0.01 {stuff_detonate}}
		   }
		else
			{stuff_detonate}
		}
	}
	{on "detonate" overload
		{stuff_detonate}
	}
}

{"spawned_warhead"
	{on spawn
		{volumes disable contact bullet blast contact_ground}
		{delay 0.2
			{if not linked
				{volumes enable contact blast contact_ground}
			}
		}
	}
}

{"targetable_impactor"
	{on spawn
;		{delay 0.5
;			{volumes "body" enable bullet}
;		}
		{components "antimissile_t" break}
		{ani_play "hit" loop}
		
	}
     {on bullet_hit overload
		{if stuff "trophy" {call "destroyed_by_kaz"}
		else stuff "radiowave" {call "missile_lock"}
		else stuff "anti_smallmissile" {call "missile_lock_long"}
		}
     }
    {on "missile_lock"
		{kill_delay "targ_for_missile"}
		{components "antimissile_t" repair}
		{delay_ex 3 "targ_for_missile"
			{components "antimissile_t" break}
		}
     }
	 {on "missile_lock_long"
		{kill_delay "targ_for_missile"}
		{components "antimissile_t" repair}
		{delay_ex 10 "targ_for_missile"
			{components "antimissile_t" break}
		}
     }
}

{"underwater_launch"
	{on spawn
		{if not altitude 0
			{tags add "underwater_launch"}
			{delay 0.05
				{with_linked_entity "missile"
					{tags add "underwater_launch"}
				}
			}

		}
	}
}
{"torpedo_impactor"
	{on "stuff_detonate"
		{stuff_detonate}
	}
	{on "detonate" overload
		{spawn "proj_restrictor" "root" x}
		{stuff_detonate}
	}
	{on "link_sound" overload}
}
;aey eiioeuniuo ?aeao eii?aeiaoa n?eoaaony ii eii?aeiaoai A?, aey iau?iuo - aaa aacen ea??ea?a.
(define "jammed_manual_control_missile"
{"allow_manual_control ecm_vulnerable_%side"
	{on "ecm_jammed"
		{if tagged "ecm_effect_3"
			{reset_manual_control}
			{volumes "missile" disable select touch}
			{able select 0}
		}
	}
}
{"allow_manual_control proj_impulse ecm_vulnerable_%side"
	{on "ecm_jammed" overload
		{if tagged "ecm_effect_4"
			{reset_manual_control}
			{volumes "missile" disable select touch}
			{able select 0}
		}
	}
}
)
("jammed_manual_control_missile" side(rus))("jammed_manual_control_missile" side(usa))
(define "missile_missed"
	{on "missile_missed"
		{volumes "proximity" disable contact}
		{tags remove "guided"}  {weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}
		{call "change_direction"}
		{damage_report "root" "component/jamming_work"}
	}
	{on overlap begin
		{if tagged "ready"
			{delay 0.1 {volumes "overlap_volume" enable overlap}}
			{if effector "helicopter_M"
				{with_effector
					{if not altitude 30
						("missile_jam" decoyprob(%decoyprob) 
							super_rad_jam(3.5) high_rad_jam(3.0) med_rad_jam(2.5) low_rad_jam(2.0)
							super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
							super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
						)
					else not altitude 65
						("missile_jam" decoyprob(%decoyprob) 
							super_rad_jam(1.75) high_rad_jam(1.25) med_rad_jam(1.0) low_rad_jam(0.75)
							super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
							super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
						)
					else
						("missile_jam" decoyprob(%decoyprob) 
							super_rad_jam(1.5) high_rad_jam(1.0) med_rad_jam(0.75) low_rad_jam(0.5)
							super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
							super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
						)	
					}
				}
			else effector "airborne"
				{with_effector
					{if not altitude 30
						("missile_jam" decoyprob(%decoyprob) 
							super_rad_jam(2.0) high_rad_jam(1.5) med_rad_jam(1.5) low_rad_jam(1.0)
							super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
							super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
						)
					else not altitude 65
						("missile_jam" decoyprob(%decoyprob) 
							super_rad_jam(1.75) high_rad_jam(1.25) med_rad_jam(1.0) low_rad_jam(0.75)
							super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
							super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
						)
					else
						("missile_jam" decoyprob(%decoyprob) 
							super_rad_jam(1.5) high_rad_jam(1.0) med_rad_jam(0.75) low_rad_jam(0.5)
							super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
							super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
						)	
					}
				}	
			else not effector "cannon"
				{if effector "vehicle"
					{with_effector
						("missile_jam" decoyprob(%decoyprob) 
							super_rad_jam(2.0) high_rad_jam(1.5) med_rad_jam(1.0) low_rad_jam(0.5)
							super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
							super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
						)
					}
				}	
			}
		}
	}
)
{"proj_dummy active"
	{on spawn {tags add "rad_guidance"}}
}
{"proj_dummy active_asm"
	{on spawn {tags add "rad_guidance"}}
}
{"proj_dummy radpassive"
	{on spawn {tags add "rad_guidance"}}
}
{"proj_dummy ir"
	{on spawn {tags add "ir_guidance"}}
}
{"proj_dummy other"
	{on spawn {tags add "other_guidance"}}
}
{"proj_dummy laser"
	{on spawn {tags add "other_guidance"}}
}