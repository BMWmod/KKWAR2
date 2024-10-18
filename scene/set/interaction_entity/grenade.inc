{"grenade"
	{on "pin_sound"
		{link_sound "pin"			"weapon/shot/pistol/tt/tt_shot"}
		{set "pin_sound" 1}
	}
	{on "pin_sound_play"
		{if flag "pin_sound"
			{play_sound "pin"}
		}
	}
	{on spawn
		;{add_view "grenade_tail" "trace" "root"}
		;{add_view "grenade_icon" "grenade_ico" "root"}
		{call "pin_sound"}
	}
	{on "onThrow"
		;{view start "trace"}
		{volumes "body" disable contact}
		{call "pin_sound_play"}
;		{delay 1.5
;			{view start "grenade_ico"}
;		}
	}
	{on "onThrowActivate"
		{volumes "body" enable contact}
	}
	{on contact
		{view stop "trace"}
		{if stuff_activated
			{if effector "human"
				{call "fall_down"}
			else effector "cannon"
				{link_grenade_to_nearest_human teleport}
			}
		}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit
		;{view stop "trace"}
	}
	{on "fall_down"
		{volumes disable contact}
		{fall_down}
	}
	{on bullet_hit
        ;{if volume "expl"
            {call "detonate"}
       ; }
	}
	{on blast
		{if min_energy 0.3
			{call "detonate"}
		}
	}
	{on overlap begin
		{if effector "trench"
			{link_grenade_to_nearest_human teleport}
		}
	}
}
{"grenade antipersonnel"
{on spawn {explosive 1}}
}
{"dynamite"
    {on "onThrowActivate"
	    ;{set "activated_dynamite" 1}
		{delay 6 {stuff_detonate breakout}}
    }
    ;{on contact
	;    {if flag "activated_dynamite" {delay 6 {stuff_detonate breakout}}}
    ;}
    ;{on ground_hit
	;    {if flag "activated_dynamite" {delay 6 {stuff_detonate breakout}}}
    ;}

}

{"grenade training"
	{on spawn
		{tags add "grenade"}
	}
}
{"f1c_script"
	{on spawn
		{tags add "f1c_script"}
		{delay 2.5 {delete}}
	}
}

{"grenade contact"
	{on "pin_sound" overload}
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact overload
		{view stop "trace"}
		{if stuff_activated
			{call "contact_detonate"}
			{if effector "human"
				{call "fall_down"}
			else effector "vehicle"
				{if tagged "gr_ic"
					{spawn "ex_tank_incendiary_shell"}
				}
			}
		}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{stuff_detonate breakout}
	}
	{on "fall_down" overload}
}
{"grenade cumul"
	{on contact
		{if stuff_activated
			{if effector "vehicle"
				{spawn "ex_tank_incendiary_shell"}
			}
		}
	}
}
{"grenade smoke"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_small"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "activate"
		{if not under_water
			{play_sound "smoke"}
			{tags add "smoke"}
			{view stop "smoke1"}
			{view start "smoke2"}
			{volumes "smoke1" enable visible}
			{spawn "smoke_volume_ground"}
			{update_visibility_patch}
			{delay 2
				{view stop "smoke2"}
				{view start "smoke3"}
				{volumes "smoke1" disable visible}
				{volumes "smoke2" enable visible}
				{update_visibility_patch}
			}
			{delay 5
				{volumes "smoke2" disable visible}
				{volumes "smoke3" enable visible}
				{update_visibility_patch}
			}
			{delay 60
				{view stop "smoke3"}
				{stop_sound "smoke"}
			}
			{delay 62
				{hide 1}
			}
		else {hide 1}}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}
{"grenade smoke_ph"
	{on spawn
		{call "add_smoke"}
		;{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_ph"	"smoke1" "smoke"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "activate"
		(define "spawn_vol"
			{spawn "smoke_vol_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{tags add "smoke"}
		{add_smoke_obstacle radius 180 fill_time 5 rise_time 5 dissolve_period 56 62}
		{delay 32 {remove_smoke_obstacle}}
		{spawn "smoke_vol_cylinder" {delay 32 {hide 1}}}
		{delay 0.2
			{view start "smoke1"}
		}
		{delay 0.8
			("spawn_vol" args cylinder 80 0 28)
			("spawn_vol" args cylinder -80 0 28)
			("spawn_vol" args cylinder 0 80 28)
			("spawn_vol" args cylinder 0 -80 28)
			("spawn_vol" args sphere 80 80 28)
			("spawn_vol" args sphere -80 -80 28)
			("spawn_vol" args sphere -80 80 28)
			("spawn_vol" args sphere 80 -80 28)
		}
		{delay 30
			{view stop "smoke1"}
		}
		{delay 32
			{hide 1}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 0.2
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 0.2
					{call "activate"}
				}
			}
		}
	}
}
{"grenade signal"
	{on "smoke_view"
		{add_view "smoke_red_test"	"smoke1" "smoke"}
	}
	{on spawn
		{setup_stuff_activator}
		{call "smoke_view"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	(define "_x"
		(+ (* %n %range) -500)
	)
	(define "art_bomb"
		{if rand 0.125
			{spawn "%name" offset ("_x" n(-1) range(%range)) 0 %z}
		else
			{if rand 0.1428
				{spawn "%name" offset ("_x" n(1) range(%range)) 0 %z}
			else
				{if rand 0.1666
					{spawn "%name" offset ("_x" n(1) range(0)) -%range %z}
				else
					{if rand 0.2
						{spawn "%name" offset ("_x" n(1) range(0)) %range %z}
					else
						{if rand 0.25
							{spawn "%name" offset ("_x" n(-1) range(%range)) -%range %z}
						else
							{if rand 0.33
								{spawn "%name" offset ("_x" n(1) range(%range)) %range %z}
							else
								{if rand 0.5
									{spawn "%name" offset ("_x" n(-1) range(%range)) %range %z}
								else
									{spawn "%name" offset ("_x" n(1) range(%range)) -%range %z}
								}
							}
						}
					}
				}
			}
		}
	)
	(define "art_bomb_test"
		{spawn "%name" offset ("_x" range(%range) n(-1)) 0 %z}
		{spawn "fx_link" offset ("_x" range(%range) n(-1)) 0 0}

		{spawn "%name" offset ("_x" range(%range) n(1)) 0 %z}
		{spawn "fx_link" offset ("_x" range(%range) n(1)) 0 0}

		{spawn "%name" offset ("_x" range(0) n(1)) -%range %z}
		{spawn "fx_link" offset ("_x" range(0) n(1)) -%range 0}

		{spawn "%name" offset ("_x" range(0) n(1)) %range %z}
		{spawn "fx_link" offset ("_x" range(0) n(1)) %range 0}

		{spawn "%name" offset ("_x" range(%range) n(-1)) -%range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(-1)) -%range 0}

		{spawn "%name" offset ("_x" range(%range) n(1)) %range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(1)) %range 0}

		{spawn "%name" offset ("_x" range(%range) n(-1)) %range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(-1)) %range 0}

		{spawn "%name" offset ("_x" range(%range) n(1)) -%range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(1)) -%range 0}
	)
	(define "rnd_art_bomb"
		{delay 2 1
			{if rand 0.33
				("art_bomb" name(%name) range(50) z(1000))
			else
				{if rand 0.5
					("art_bomb" name(%name) range(80) z(1000))
				else
					("art_bomb" name(%name) range(120) z(1000))
				}
			}
		}
	)
	{on "stack_art_bomb"
		("rnd_art_bomb" name(art_bomb))
		("rnd_art_bomb" name(art_bomb))
		("rnd_art_bomb" name(art_bomb))
		;("art_bomb_test" name(art_bomb) range(40) z(1000))
	}
	{on "activate"
		{setup_stuff_activator}
		{volumes disable blast}
		{play_sound "smoke" 1}
		{tags add "signal"}
		{view start "smoke1"}
		{delay 6 1
			{call "stack_art_bomb"}
			{delay 3
				{view stop "smoke1"}
				{stop_sound "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}
{"grenade signal heavy"
	{on "smoke_view" overload
		{add_view "smoke_pureyellow_test"	"smoke1" "smoke"}
	}
	{on "stack_art_bomb" overload
		("rnd_art_bomb" name(art_bomb_heavy))
		("rnd_art_bomb" name(art_bomb_heavy))
		("rnd_art_bomb" name(art_bomb_heavy))
	}
}
{"grenade mortar"
	{on "smoke_view"
		{add_view "smoke_red_test"	"smoke1" "smoke"}
	}
	{on spawn
		{setup_stuff_activator}
		{call "smoke_view"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "stack_art_bomb"
		("rnd_art_bomb" name(art_mortar_80))
		("rnd_art_bomb" name(art_mortar_80))
		("rnd_art_bomb" name(art_mortar_80))
	}
	{on "activate"
		{setup_stuff_activator}
	    {call "smoke_view"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
		{volumes disable blast}
		{play_sound "smoke" 1}
		{tags add "signal"}
		{view start "smoke1"}
		{delay 6 1
			{call "stack_art_bomb"}
			{delay 3
				{view stop "smoke1"}
				{stop_sound "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}
{"grenade signal mission"
	{on "stack_art_bomb" overload}
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}

{"grenade smoke mortar_smoke"
	{on spawn
		{volumes disable touch select}
		{call "activate"}
	}
}
{"smoke_probe"
	{on spawn
	    {delay 0.5 {delete}}
	}
	{on bullet_hit overload
		{impulse up 0.01 com}
		{gravity 0.01}
		{volumes "body" disable all}
		{if 
			(define "check_dir"
				 tagged "%dir"
					{if stuff "tanksmoke_airburst"
						{spawn "smoke_shell_fly" "smoke%dir" x 
							{impulse up 50 2 forward 100 rnd_dir 2.5 com}
							{gravity 0.9}
							{delay 0.2
								{spawn "ex_smokeshell"}
								{spawn "smoke_volume"}
								{delete}
							}
						}
					else stuff "tanksmoke"
						{spawn "smoke_shell_fly" "smoke%dir" x 
							{impulse up 0.1 forward 30 rnd_dir 2.5}
							{add_view	"wp_smoke"	"grenade_tail"	"root"}
							{view start "grenade_tail"}
							{view show		"grenade_tail"}
						}
					}				 
			)
			("check_dir" dir(0_0))
			else ("check_dir" dir(0_m10))
			else ("check_dir" dir(0_m20))
			else ("check_dir" dir(0_m30))
			else ("check_dir" dir(0_m40))
			else ("check_dir" dir(0_10))
			else ("check_dir" dir(0_20))
			else ("check_dir" dir(0_30))
			else ("check_dir" dir(0_40))
			else ("check_dir" dir(15_0))
			else ("check_dir" dir(15_m10))
			else ("check_dir" dir(15_m20))
			else ("check_dir" dir(15_m30))
			else ("check_dir" dir(15_m40))
			else ("check_dir" dir(15_10))
			else ("check_dir" dir(15_20))
			else ("check_dir" dir(15_30))
			else ("check_dir" dir(15_40))
			else ("check_dir" dir(30_0))
			else ("check_dir" dir(30_m10))
			else ("check_dir" dir(30_m20))
			else ("check_dir" dir(30_m30))
			else ("check_dir" dir(30_m40))
			else ("check_dir" dir(30_10))
			else ("check_dir" dir(30_20))
			else ("check_dir" dir(30_30))
			else ("check_dir" dir(30_40))
			else
		}

		{delete}
	}

}
{"molotov_coctail"
	{on "pin_sound" overload}
	{on bullet_hit
		{fire radius 1.5 time 40 heating 1 effector}
		{call "detonate"}
	}
	{on blast
		{if min_energy 0.3
			{fire radius 1.5 time 40 heating 1 effector}
			{call "detonate"}
		}
	}
	{on "ground_detonate"
		{fire radius 1.5 time 40 heating 1}
	}
	{on "contact_detonate" overload
		{if effector "construction"
			{volumes disable bullet contact blast}
			{fire radius 1 time 40 heating 1 effector}
			{burn volume fx "smoke_dead_small" time 40 5 fake even_law}
			{delay 0.1
				{call "detonate"}
			}
		else
			{with_effector {burn fx "fire_molot" time 40 5 fake} {with_effector}}
			{call "detonate"}
		}
	}
}
{"smoke_shell_fly"
	{on spawn
		{delay 5 {spawn "smoke_shell"} {delete}}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{spawn "smoke_shell"} {delete}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{spawn "smoke_shell"} {delete}
				}
			}
		}
	}
}
{"smoke_shell"	;для дымовых БП
	{on spawn
		{call "activate"}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}

;=====Cluster system by Timosh=====
{"vog_25p_exp"
	{on spawn
		{impulse up 10 1 rnd_dir 1}
		{delay 0.12
			{stuff_detonate}
		}
	}
}
{"vog_25pm_exp"
	{on spawn
		{impulse up 10 1 rnd_dir 1}
		{delay 0.12
			{stuff_detonate}
		}
	}
}
{"m397p_exp"
	{on spawn
		{impulse up 10 1 rnd_dir 1}
		{delay 0.12
			{stuff_detonate}
		}
	}
}
{"mk30abm_fg_exp"
	{on spawn
		{if altitude 1 {stuff_detonate}
		else
			{impulse up 20 6 rnd_dir 20}
			{delay 0.04
				{stuff_detonate}
			}
		}
	}
}
{"shell_fr_gpr-ab-t_40mm_exp"
	{on spawn
		{if altitude 1 {stuff_detonate}
		else
			{impulse up 20 6 rnd_dir 20}
			{delay 0.04
				{stuff_detonate}
			}
		}
	}
}
{"shell_ger_abm_120_exp"
	{on spawn
		{if altitude 1 {stuff_detonate}
		else
			{impulse up 20 6 rnd_dir 20}
			{delay 0.06
				{stuff_detonate}
			}
		}
	}
}
{"telnik_abm_exp"
	{on spawn
		{if altitude 1 {stuff_detonate}
		else
			{impulse up 20 6 rnd_dir 20}
			{delay 0.08
				{stuff_detonate}
			}
		}
	}
}
{"grenade_xm25_fg_exp"
	{on spawn
		{impulse up 8 1 rnd_dir 1}
		{delay 0.15
			{stuff_detonate}
		}
	}
}
;-------------------------------------------------------------------------
;Cluster shells
;if real shell has less than 20 subm - we do real number
;if from 20 to 40 - we do 20-30
;if from 40 to 100 - we do 30-50
;if from 100 to 300 - we do 50-70
; if more than 300 - we do 70-100
(define "cluster_spreader_1gen"
	{on spawn
		{volumes "body" disable contact blast}
		{impulse up 5 com}
		{delay 0.1 {spawn %0}}
		{delay 0.2 {spawn %0}}
		{delay 0.3 {spawn %0}}
		{delay 0.4 {spawn %0}}
		{delay 0.5 {spawn %0}}
		{delay 0.6 {spawn %0}}
		{delay 0.7 {spawn %0}}
		{delay 0.8 {spawn %0}}
		{delay 0.9 {spawn %0} {delete}}
		{delay 1 {delete}	} ;если сам не исчез
	}
)
(define "cluster_spreader_2gen_big"
	{on spawn
		{volumes "body" disable contact blast}
		{impulse up 5 com}
		{delay 0.1 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.2 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.3 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.4 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.5 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.6 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.7 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.8 {spawn %0 {impulse up 2 rnd_dir 10}}}
		{delay 0.9 {spawn %0 {impulse up 2 rnd_dir 10}} {delete}}
		{delay 1 {delete}	} ;если сам не исчез
	}
)
(define "cluster_spreader_2gen_small"
	{on spawn
		{volumes "body" disable contact blast}
		{impulse up 5 com}
		{delay 0.1 {spawn %0 {impulse up 3 rnd_dir 10}}}
		{delay 0.2 {spawn %0 {impulse up 3 rnd_dir 10}}}
		{delay 0.3 {spawn %0 {impulse up 3 rnd_dir 10}}}
		{delay 0.4 {spawn %0 {impulse up 3 rnd_dir 10}}}
		{delay 0.5 {spawn %0 {impulse up 3 rnd_dir 10}}}
		{delay 0.6 {spawn %0 {impulse up 3 rnd_dir 10}} {delete}}
		{delay 0.7 {delete}	} ;если сам не исчез
	}
)
(define "cluster_shell_1up"
	{spawn %subm  no_position no_normal {impulse up 15 0.5 dir %forward rnd_dir %spread com}}
)
(define "cluster_shell_2up"
	{spawn %subm  no_position no_normal {impulse up 15 0.5 dir %forward rnd_dir %spread com}}
	{spawn %subm  no_position no_normal {impulse up 22 0.5 dir (+ %forward 15) rnd_dir %spread com}}
)
(define "cluster_shell_5up"
	("cluster_shell_1up" subm(%subm) forward(%forward) spread(%spread))
	("cluster_shell_2up" subm(%subm) forward(%forward) spread(%spread))
	("cluster_shell_2up" subm(%subm) forward(%forward) spread(%spread))
)
(define "cluster_shell_5"
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 0.5 %spread)}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 1.0 %spread)}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 1.5 %spread)}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 2.0 %spread)}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 2.5 %spread)}}
)
(define "cluster_shell_5_ring"
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 1.5 %spread)  %rnd_spread}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 1.5 %spread)  %rnd_spread}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 1.5 %spread)  %rnd_spread}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 1.5 %spread)  %rnd_spread}}
	{spawn %subm {impulse up 1 0.5 dir 25 0.5 rnd_dir (* 1.5 %spread)  %rnd_spread}}
)
(define "cluster_shell_10"
	("cluster_shell_5" subm(%subm) spread(%spread))
	("cluster_shell_5" subm(%subm) spread(%spread))
)
(define "cluster_shell_10_ring"
	("cluster_shell_5_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_5_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_20"
	("cluster_shell_10" subm(%subm) spread(%spread))
	("cluster_shell_10" subm(%subm) spread(%spread))
)
(define "cluster_shell_20_ring"
	("cluster_shell_10_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_10_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_25_ring"
	("cluster_shell_5_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_10_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_10_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_30"
	("cluster_shell_20" subm(%subm) spread(%spread))
	("cluster_shell_10" subm(%subm) spread(%spread))
)
(define "cluster_shell_30_ring"
	("cluster_shell_10_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_20_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_35_ring"
	("cluster_shell_5_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_10_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_20_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_40"
	("cluster_shell_20" subm(%subm) spread(%spread))
	("cluster_shell_20" subm(%subm) spread(%spread))
)
(define "cluster_shell_40_ring"
	("cluster_shell_20_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_20_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_50"
	("cluster_shell_20" subm(%subm) spread(%spread))
	("cluster_shell_30" subm(%subm) spread(%spread))
)
(define "cluster_shell_50_ring"
	("cluster_shell_20_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_30_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_55_ring"
	("cluster_shell_5_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_20_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_30_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_60"
	("cluster_shell_30" subm(%subm) spread(%spread))
	("cluster_shell_30" subm(%subm) spread(%spread))
)
(define "cluster_shell_60_ring"
	("cluster_shell_30_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
	("cluster_shell_30_ring" subm(%subm) spread(%spread) rnd_spread(%rnd_spread))
)
(define "cluster_shell_70"
	("cluster_shell_20" subm(%subm) spread(%spread))
	("cluster_shell_50" subm(%subm) spread(%spread))
)
(define "cluster_shell_100"
	("cluster_shell_50" subm(%subm) spread(%spread))
	("cluster_shell_50" subm(%subm) spread(%spread))
)
(define "cluster_shell_150"
	("cluster_shell_50" subm(%subm) spread(%spread))
	("cluster_shell_50" subm(%subm) spread(%spread))
	("cluster_shell_50" subm(%subm) spread(%spread))
)
(define "cluster_shell_200"
	("cluster_shell_50" subm(%subm) spread(%spread))
	("cluster_shell_50" subm(%subm) spread(%spread))
	("cluster_shell_50" subm(%subm) spread(%spread))
	("cluster_shell_50" subm(%subm) spread(%spread))
)

{"cw_shell_fuse_detector"
{on spawn {impulse up -555 com} {delay 5.0 {delete}}}
}
{"cw_shell_radio_fuse_detector"
	{on spawn {delay 1.5 {delete}}}
	
	{on contact
	 {if altitude 15 {volumes "body" enable bullet}}
    }
	
}

;merged into one object for cwbs usage
{"cw_shell_detector"
	{on spawn {delay 1.5 {delete}}
;		{volumes "body" enable bullet}
	}
	{on bullet_hit
	  {if not hit_side bottom
		;Паттерн рассеяния кассетных снарядов такой: 1/8 субб/п идет с малым рассеянием в центр эллипса,
		;остальные 7/8 образуют тонкое кольцо на определенном расстоянии, т.к. отбрасываются вращением снаряда.
		;Мы это реализуем как рассеяние по сфере (иначе технически нельзя) с малым разбросом - получаем плотное кольцо и малоплотную середину.
		;А вот рассеяние на крупных б/п равномерное.
		{if stuff "bullet152_RUS rok"		;40 real
			{spawn "ex_air_big"}
;			("cluster_shell_40" subm("cluster_subm_152") spread(10))
			("cluster_shell_40_ring" subm("cluster_subm_152") spread(10) rnd_spread(0.1))
			{bullet_detonate}
		else stuff "bullet155_USA cl"		;60 real	
			{spawn "ex_air_big"}
;			("cluster_shell_60" subm("m42_submunition") spread(10))
			("cluster_shell_60_ring" subm("m42_submunition") spread(10) rnd_spread(0.1))
			{bullet_detonate}
		else stuff "bullet155_cn cl"		;63 real, Chinese copies of M42	
			{spawn "ex_air_big"}
;			("cluster_shell_60" subm("m42_submunition") spread(10))
			("cluster_shell_60_ring" subm("m42_submunition") spread(10) rnd_spread(0.1))
			{bullet_detonate}
		else stuff "bullet120_cn cl"		;32 real	
			{spawn "ex_air_big"}
;			("cluster_shell_30" subm("type90_submunition") spread(10))
			("cluster_shell_30_ring" subm("type90_submunition") spread(10) rnd_spread(0.1))
			{bullet_detonate}
		else stuff "bullet203_rus cl"		;24 real	
			{spawn "ex_air_big"}
			("cluster_shell_20" subm("3o16_submunition") spread(12))
			{bullet_detonate}
		else stuff "bullet122_cn cl"		;63 real, Chinese copies of M42	
			{spawn "ex_air_big"}
;			("cluster_shell_60" subm("m42_submunition") spread(10))
			("cluster_shell_60_ring" subm("m42_submunition") spread(10) rnd_spread(0.1))
			{bullet_detonate}
		else stuff "rbk_cn cl"	;140 real
			{spawn "ex_air_big"}
			("cluster_shell_50" subm("250-3_submunition") spread(10))
			{bullet_detonate}
		else stuff "m270_aw"
			{bullet_detonate}
		else stuff "rbk_cn tb"	;250kg class odab
			{bullet_detonate}
		else stuff "altitude_burst"	;artillery shells with altitude fuse
			{bullet_detonate}
		else stuff "bullet155_USA spbe"		;2 real	
			{spawn "ex_air_big"}
			("cluster_shell_2up" subm("smart155") forward(30) spread(2 1))
			{bullet_detonate}
		else stuff "m270 cl"		;600 real
			{spawn "ex_air_big"}
			("cluster_shell_200" subm("m77_mlrs_submunition") spread(13))
		else stuff "atacms cl"	;275 real
			{spawn "ex_air_big"}
			("cluster_shell_150" subm("m74_mlrs_submunition") spread(17))
		else stuff "lars2 mine"		;5 real	
			{spawn "ex_air_big"}
			("cluster_shell_5" subm("at2_mine_in_fly") spread(12))
		else stuff "grad mine"		;5 real	
			{spawn "ex_air_big"}
			("cluster_shell_5" subm("pom_2") spread(12))
		else stuff "grad spbe"		;2 real	
			{spawn "ex_air_big"}
			("cluster_shell_2up" subm("spbe_9n282") forward(40) spread(2 1))
		else stuff "grad clcn"		;39 real	
			{spawn "ex_air_big"}	;Type-90 DPICM
			("cluster_shell_30" subm("type90_submunition") spread(10))
		else stuff "grad cl"		;45 real	
			{spawn "ex_air_big"}
			("cluster_shell_30" subm("9m218_submunition") spread(10))
		else stuff "grad ic"		;180 real	
			{spawn "ex_air_big"}
			("cluster_shell_70" subm("9m22s_submunition") spread(7))
		else stuff "9m525 cl"		;72 real	
			{spawn "ex_air_big"}
			("cluster_shell_70" subm("9n235_submunition") spread(10))
		else stuff "9m549 cl"		;72 real	
			{spawn "ex_air_big"}
			("cluster_shell_70" subm("9n235_submunition") spread(7))
		else stuff "9m55k3 mine"		;64 real	
			{spawn "ex_air_big"}
			("cluster_shell_40" subm("pom_2") spread(15))
		else stuff "9m531 cl"		;588-646 real	
			{spawn "ex_air_big"}
			("cluster_shell_200" subm("9m218_submunition") spread(13))
		else stuff "9m546 cl"		;552 real	
			{spawn "ex_air_big"}
			("cluster_shell_200" subm("9m218_submunition") spread(13))
		else stuff "9m533 spbe"		;5real	
			{spawn "ex_air_big"}
			("cluster_shell_5up" subm("spbe_9n282") forward(40) spread(6 1))
		else stuff "phl03 cl brc4"		;400 real	
			{spawn "ex_air_big"}	;Type-90 DPICM
			("cluster_shell_150" subm("type90_submunition") spread(13))
		else stuff "cluster"
			{spawn "cluster_expl" no_normal no_position}
			{bullet_detonate}
	
		}
		{delay 0.1 {delete}}
	  }
	}
}
;все имена уникальные

{"cw_shell_fuse_detector"
{on spawn {impulse up -555 com} {delay 5.0 {delete}}}
}
{"cw_shell_radio_fuse_detector"
	{on spawn {delay 0.5 {delete}}}
	
	{on contact
	 ;{if effector "airborne"
	  ;{volumes "body" enable bullet}
	 ; else effector "small_UAV"
	  ;{volumes "body" enable bullet}
	 ;}
	 {if altitude 15 {volumes "body" enable bullet}}
    }
	
}
{"cw_shell_cl_detector"
	{on spawn
		{if not altitude 15
			{volumes "body" enable bullet}
		}
	}
}
{"cw_shell_cl_detector_lowalt"
	{on spawn
		{if not altitude 10
			{volumes "body" enable bullet}
		}
	}
}
{"cw_shell_r_detector"
	{on spawn {delay 1.5 {delete}}
		{if not altitude 7
			{volumes "body" enable bullet}
		}
	}
	{on bullet_hit
		{if not hit_side bottom
			{bullet_detonate}
		}
	}
}
{"cw_shell_spbe_detector"
	{on spawn
		{if not altitude 20
			{volumes "body" enable bullet}
		}
	}
}
{"cw_rocket_cl_detector"
	{on spawn
		{if not altitude 25
			{volumes "body" enable bullet}{delay 0.2 {volumes "body" disable bullet}}
		}
	}
}
{"cw_rocket_aw_detector"
	{on spawn
		{if not altitude 7
			{volumes "body" enable bullet}
		}
	}
}


















;для РБК-250
{"rbk250_cluster"
	{on spawn
		{volumes "body" disable contact blast}
;		{impulse up 5 com}
		("cluster_shell_70" subm("ao1_submunition") spread(10))

		{delay 0.1 {delete}	} ;если сам не исчез
	}
	;("cluster_spreader_1gen" args "ao1_submunition")
}

;для AGM-154
{"AGM-154_cluster"
	;("cluster_spreader_1gen" args "blu-97_submunition")
		{on spawn
		{volumes "body" disable contact blast}

	("cluster_shell_20" subm("blu-97_submunition") spread(10))
			{delay 0.1 {delete}	} ;если сам не исчез
	}

}



{"submunition"	;для кластерных БП
	{on spawn
		{volumes "body" disable contact blast}
		{delay 0.1
			{set "activated" 1}
			{volumes "body" enable contact}
		}
		{delay 7 1 {stuff_detonate}} ;если сам не исчез
	}
	{on ground_hit
;		{if flag "activated"
;			{if not effector "cluster_shell"
				{stuff_detonate}
;			}
;		else 	{impulse up 0.2}}
	}
	{on contact overload
		{if effector "cluster_shell"
		else  effector "submunition"
		else  effector "vehicle"
		   {if not flag "detonate"
			{set "detonate" 1}{call "spawn_cm_jet"} {delay 0.01 {stuff_detonate}}
		   }
		else
			{stuff_detonate}
		}
	}
}

(define "small_cm_impactor"
{"small_cm_impactor_%penetration"
	{on "spawn_cm_jet"
		{spawn "cw_cumulative_jetthrower%penetration" dir_velocity} {stuff_detonate}
	}
}
)
("small_cm_impactor" penetration(60))
("small_cm_impactor" penetration(70))
("small_cm_impactor" penetration(80))
("small_cm_impactor" penetration(100))
("small_cm_impactor" penetration(120))
("small_cm_impactor" penetration(125))
("small_cm_impactor" penetration(140))
("small_cm_impactor" penetration(150))
("small_cm_impactor" penetration(230))
("small_cm_impactor" penetration(500))

{"ao1_submunition"
	{on spawn overload
		{volumes "body" disable contact blast}
		{impulse up -2 rnd_dir 8}
		{delay 0.1
			{set "activated" 1}
			{volumes "body" enable contact}
		}
		{delay 7 {stuff_detonate}} ;если сам не исчез
	}
}
{"blu-97_submunition"
	{on spawn overload
		{volumes "body" disable contact blast}
		{impulse up 2 rnd_dir 10}
		{delay 0.1
			{set "activated" 1}
			{volumes "body" enable contact}
		}
	}
	{on ground_hit overload
;		{if flag "activated"
			{if not effector "cluster_shell"
			      {if terrain_fx "sand"			;из-за специфики детонатора на мягком грунте может не сработать
				{if rand 0.6 {stuff_detonate}}
			      else terrain_fx "snow"
				{if rand 0.6 {stuff_detonate}}
			      else terrain_fx "water"
				{if rand 0.6 {stuff_detonate}}
			      else terrain_fx "grass"
				{if rand 0.8 {stuff_detonate}}
			     else
				{stuff_detonate}
			     }
			}
;		else {impulse up 0.2}
;		}
	}
}
{"9m22s_submunition"
	{on spawn overload
		{add_view	"9m22c_air"	"smoke_dead_small"	"root"}
		{view start "smoke_dead_small"}
		{view show "smoke_dead_small"}
		{delay 1 {volumes "body" enable contact}}
		{delay 7 1 {delete}}
	}
	{on ground_hit overload
		{spawn "9m22c_ground"}
		{fire radius 1 time 5 heating 3}
		{delete}
	}
	{on contact
		{if effector "cluster_shell"
		else  effector "submunition"
		else 
			{spawn "9m22c_ground"}
			{fire radius 1 time 5 heating 3}
			{stuff_detonate}
		}
	}
}
;-------------------------------------------------------------------------
;for cluster mines in fly
{"cluster_mine"
	{on spawn
		{volumes "body" disable contact blast}
		{delay 0.1
			{set "activated" 1}
			{volumes "body" enable contact}
		}
		{delay 20 3 {call "deploy"}} ;если сам не исчез
	}
	{on ground_hit
		{if flag "activated"
			{if not effector "cluster_shell"
				{delay 7 2 {call "deploy"}}
			}
		else 	{impulse up 0.2}}
	}
	{on "deploy" {delay 0.1 {delete}}}
}

{"pom_2"
	{on "deploy"
		{spawn "ex_bul_zenit"}
		{spawn "pom_2_installed"}
		{delete}
	}
}
{"at2_mine_in_fly"
	{on "deploy"
		{spawn "ex_bul_zenit"}
		{spawn "at2_mine"}
		{delete}
	}
}
;-------------------------------------------------------------------------
;for cluster mines on ground
{"cluster_mine_ground"
	{on spawn
		{player -1}
		{tags add "mine_planted"}
		{volumes "detector1" disable all}	{volumes "detector2" disable all}
		{volumes "detector3" disable all}	{volumes "detector4" disable all}
		{bone hide "detector1"}	{bone hide "detector2"}
		{bone hide "detector3"}	{bone hide "detector4"}
		{delay 3
			{spawn "ex_bul_zenit"}
			{volumes "detector1" enable all}	{volumes "detector2" enable all}
			{volumes "detector3" enable all}	{volumes "detector4" enable all}
			{bone show "detector1"}	{bone show "detector2"}
			{bone show "detector3"}	{bone show "detector4"}
		}
	}
	{on "detonate" {stuff_detonate}}
	{on contact {call "detonate"}}
	{on blast_hit
		{if min_energy 3
			{if not stuff "mine"
				{call "detonate"}
			}
		}	
	}
}
{"at2_mine"
	{on "detonate" overload 
	  ;{delay 0.1 0.03
		{spawn "spbe-d_fire" "foresight" x}
		{spawn "at2_mine_core" "foresight" x
			{impulse up 0.1 forward 100 com}
			{delay 0.1 {delete}}
		}
		{stuff_detonate}
	   ;}
	}
	{on blast
	{if min_energy 1
	{spawn "spbe-d_fire" "foresight" x}
		{spawn "at2_mine_core" "foresight" x
			{impulse up 0.1 forward 100 com}
			{delay 0.1 {delete}}
		}
		{stuff_detonate}
	}
	}
}

;-------------------------------------------------------------------------
;далее - для совместимости, на всякий случай.
{"cluster_expl"
	{on spawn
		{volumes "body" disable contact blast}
		{impulse up 5 com}
		{delay 0.1 {spawn "cluster_shell"}}
		{delay 0.2 {spawn "cluster_shell"}}
		{delay 0.3 {spawn "cluster_shell"}}
		{delay 0.4 {spawn "cluster_shell"}}
		{delay 0.5 {spawn "cluster_shell"}}
		{delay 0.6 {spawn "cluster_shell"}}
		{delay 0.7 {spawn "cluster_shell"}}
		{delay 0.8 {spawn "cluster_shell"}}
		{delay 0.9 {spawn "cluster_shell"} {delete}}
		{delay 1 {delete}	} ;если сам не исчез
	}
}
{"cluster_expl_2gen"
	{on spawn
		{volumes "body" disable contact blast}
		{impulse up 5 com}
		{delay 0.1 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.2 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.3 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.4 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.5 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.6 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.7 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.8 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}}}
		{delay 0.9 {spawn "cluster_expl" {impulse up 2 rnd_dir 10}} {delete}}
		{delay 1 {delete}	} ;если сам не исчез
	}
}

{"cluster_shell"	;для кластерных БП
	{on spawn
		{volumes "body" disable contact blast}
		{impulse up 2 rnd_dir 10}
		{delay 0.1
			{set "activated" 1}
		}
		{delay 7 {delete}	{blastwave c4 4 r0 1 r1 4} {spawn "ex_anti_size1"}} ;если сам не исчез
	}
	{on ground_hit
		{if flag "activated"
			{if not effector "cluster_shell"
				{blastwave c4 0.7 r0 4 r1 5.5}
				{blastwave c4 1.2 r0 3.8 r1 4}
				{blastwave c4 2.5 r0 1 r1 2}
				{spawn "ex_anti_size1"}
				{delete}
			}
		else 
			{impulse up 0.2}
		}
	}
	{on contact
		{if flag "activated"
			{if not effector "cluster_shell"
			     {if not effector "cluster_shell"
				{blastwave c4 4 r0 1 r1 4}
				{spawn "ex_anti_size1"}
				{delete}
			     }
			}
		else 
			{impulse up 0.2}
		}
	}
}
;======================================

;растяжка
;===========================================
{"grenade_mine"
	{on spawn
		{tags add "mine_planted"}
		{volumes "detector" disable all}
		{delay 2
			{volumes "detector" enable contact blast touch}
			{volumes "select" enable touch}
		}
	}
	{on contact
		{if rand 0.3 {with_effector {spawn "grenade_mine_alarm"}{with_effector}}}
		{call "detonate"}
	}
	{on "detonate"
		{volumes "detector" disable all}
		{delay 0.75 0.25
		     {with_linked_entity "grenade"
			{stuff_detonate}
		     }
		     {delete}
		}
	}
	{on blast_hit
		{if min_energy 2
;		      {if volume "body"
			     {with_linked_entity "grenade"
					{stuff_detonate}
			     }
			     {delete}
;		      else 
;					{call "detonate"}
;		      }
		}	
	}
}

{"grenade_mine_alarm"
	{on spawn
		{delay 0.1
			{explosive 1}
			{able "burning" 1}
		}
		{delay 3
			{explosive 0}
			{able "burning" 0}
			{if tagged "15s_timer"
				{delay 12 {delete}}
			else
				 {delete}
			}
		}
		
	}
}
{"grenade_gas_alarm"
	{on spawn
		{delay 0.1
			{explosive 1}
			{able "burning" 1}
		}
		{delay 3
			{if tagged "15s_timer"
				{delay 12 {delete}}
			else
				 {delete}
			}
		}
		
	}
}
(define "grenademine"
	{"grenade_mine_%grenademine_name" 
		{on "demine"
			{spawn "%entityname"}
			{delete}
		}
	}
)
	(include "/lists/grenades.inc")
	("grenademines")

