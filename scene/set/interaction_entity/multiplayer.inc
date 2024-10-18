{"flag_1"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_1"	"fx" "fx_number"}
	}
}

{"flag_2"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_2"	"fx" "fx_number"}
	}
}

{"flag_3"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_3"	"fx" "fx_number"}
	}
}

{"flag_4"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_4"	"fx" "fx_number"}
	}
}

{"flag_5"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_5"	"fx" "fx_number"}
	}
}

{"flag_6"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_6"	"fx" "fx_number"}
	}
}

{"flag_7"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_7"	"fx" "fx_number"}
	}
}

{"flag_8"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_8"	"fx" "fx_number"}
	}
}

{"flag_9"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_9"	"fx" "fx_number"}
	}
}

{"flag_10"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_10"	"fx" "fx_number"}
	}
}

{"flag_11"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_11"	"fx" "fx_number"}
	}
}

{"flag_12"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_12"	"fx" "fx_number"}
	}
}

{"flag_13"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_13"	"fx" "fx_number"}
	}
}

{"flag_14"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_14"	"fx" "fx_number"}
	}
}

{"flag_15"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_15"	"fx" "fx_number"}
	}
}

{"flag_16"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_16"	"fx" "fx_number"}
	}
}

{"flag_17"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_17"	"fx" "fx_number"}
	}
}

{"flag_frontlines"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_frontlines"	"fx" "fx_number"}
	}
}

{"flag_frontlines_slave"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_frontlines_slave"	"fx" "fx_number"}
	}
}

{"spawn"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "spawn"	"fx" "fx_number"}
	}
}

{"flag_ammo"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "flag_ammo"	"fx" "fx_number"}
	}
}

{"supply_ammo"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "supply_ammo"	"fx" "fx_number"}
	}
}

{"evacuation"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "evacuation"	"fx" "ammo"}
	}
}

{"fortification"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "fortification"	"fx" "fx_number"}
	}
}

{"spawn"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "spawn"	"fx" "fx_number"}
	}
}

{"mp_pointer"
    {on spawn
        (mod  "mp" 
		{call "add_number"}
		{delay 0
            {view start "fx"}
		}
		)
    }
	{on "add_number" overload
		{add_view "mp_pointer"	"fx" "fx_mp_pointer"}
	}
}

{"mp_watchout"
	{on spawn
		{call "add_number"}
		{delay 0
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "mp_watchout" "fx" "fx_mp_pointer"}
	}
}

{"mp_attack"
	{on spawn
		{call "add_number"}
		{delay 0
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "mp_attack" "fx" "fx_mp_pointer"}
	}
}

{"mp_defend"
	{on spawn
		{call "add_number"}
		{delay 0
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "mp_defend" "fx" "fx_mp_pointer"}
	}
}

{"mp_enemy"
	{on spawn
		{call "add_number"}
		{delay 0
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "mp_enemy" "fx" "fx_mp_pointer"}
	}
}

{"mp_going"
	{on spawn
		{call "add_number"}
		{delay 0
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "mp_going" "fx" "fx_mp_pointer"}
	}
}

{"mp_help"
	{on spawn
		{call "add_number"}
		{delay 0
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "mp_help" "fx" "fx_mp_pointer"}
	}
}

{"grenade smoke paradrop_ammo"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_norm"	"smoke3" "root"}
	}
	{on "activate"
		{delay 10.0
			{hide 1}
            {spawn "paradrop_ammo"}
			{start_sound "world/ambient/bomber_flyby.wav"}
		}
	}
}
{"grenade smoke paradrop_ammo_heavy"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_norm"	"smoke3" "root"}
	}
	{on "activate"
		{delay 10.0
			{hide 1}
            {spawn "paradrop_ammo_heavy"}
			{start_sound "world/ambient/bomber_flyby.wav"}
		}
	}
}
{"paradrop"
	{on spawn
		{ani_play "flight"}
		{delay 4.0
			{ani_play "landing"}
		}
	}
}

{"mp_target_marker"
	{on spawn
		{physics_work 0}
		{able inventory_operation 0}
		{delay 700
			{if not flag "turret_teared"
				{delete}
			}
		}
 ;       (mod  "mp" 
;			{add_view "mp_persistent_pointer"	"fx" "fx_mp_pointer"}
;			{delay 0
;				{view start "fx"}
;			}
;		)
			{add_view "mp_persistent_pointer_default"	"default" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_mortar"	"mortar" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_atgm"	"atgm" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_stan"	"stan" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_art"	"art" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_tank"	"tank" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_sam"	"sam" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_bmp"	"bmp" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_car"	"car" "fx_mp_pointer"}
			{delay 0 {view start "default"} }
	}
			
		(define "set_decal"
			{view pause "default"}
			{view pause "mortar"}
			{view pause "atgm"}
			{view pause "art"}
			{view pause "stan"}
			{view pause "tank"}
			{view pause "sam"}
			{view pause "bmp"}
			{view pause "car"}
			{view start "%decal"}
			{tags remove "default"}
			{tags remove "mortar"}
			{tags remove "atgm"}
			{tags remove "art"}
			{tags remove "stan"}
			{tags remove "tank"}
			{tags remove "sam"}
			{tags remove "bmp"}
			{tags remove "car"}
			{tags add "%decal"}
		)
		{on "cwsh_switch_hatch" overload
			{set "turret_teared" 1}
			{if tagged "mortar" ("set_decal" decal(atgm))
			else tagged "atgm" ("set_decal" decal(art))
			else tagged "art" ("set_decal" decal(stan))
			else tagged "stan" ("set_decal" decal(tank))
			else tagged "tank" ("set_decal" decal(sam))
			else tagged "sam" ("set_decal" decal(bmp))
			else tagged "bmp" ("set_decal" decal(car))
			else tagged "car" ("set_decal" decal(default))
			else	("set_decal" decal(mortar))}
		}
	{on "smokescreen" overload
		{call "cwsh_switch_hatch"}
	}
	{on "specability" {delete}}
	{on blast{if min_energy 5 {delete}}}
}
{"persistent_marker_tester"
	{on spawn
		{physics_work 0}
			{add_view "mp_persistent_pointer_default"	"default" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_mortar"	"mortar" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_atgm"	"atgm" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_stan"	"stan" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_art"	"art" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_tank"	"tank" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_sam"	"sam" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_bmp"	"bmp" "fx_mp_pointer"}
			{add_view "mp_persistent_pointer_car"	"car" "fx_mp_pointer"}
			{delay 0 {view start "default"} }
	}

	(define "set_decal"
		{view pause "default"}
		{view pause "mortar"}
		{view pause "atgm"}
		{view pause "art"}
		{view pause "stan"}
		{view pause "tank"}
		{view pause "sam"}
		{view pause "bmp"}
		{view pause "car"}
		{view start "%decal"}
	)
	{on "set_decal"
		{if effector "truck_mortar" ("set_decal" decal(mortar))
		else effector "sam_radar" ("set_decal" decal(sam))
		else effector "atgm" ("set_decal" decal(atgm))
		else effector "cw_artillery" ("set_decal" decal(art))
		else effector "cannon" ("set_decal" decal(stan))
		else effector "medium_M" ("set_decal" decal(tank))
		else effector "heavy_M" ("set_decal" decal(tank))
		else effector "armored_car_M" ("set_decal" decal(bmp))
		else effector "light_M" ("set_decal" decal(bmp))
		else effector "car" ("set_decal" decal(car))
		else	("set_decal" decal(default))}
	}

}