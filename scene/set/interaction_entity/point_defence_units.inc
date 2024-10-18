{"sea_sparrow"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter00"	"shooter00"}
		{add_view	 "flash_gun_big"	"shooter01"	"shooter01"}
		{add_view	 "flash_gun_big"	"shooter02"	"shooter02"}
		{add_view	 "flash_gun_big"	"shooter03"	"shooter03"}
		{add_view	 "flash_gun_big"	"shooter04"	"shooter04"}
		{add_view	 "flash_gun_big"	"shooter05"	"shooter05"}
		{add_view	 "flash_gun_big"	"shooter06"	"shooter06"}
		{add_view	 "flash_gun_big"	"shooter07"	"shooter07"}
		{add_view	 "startsmoke_big"	"shooter00"	"tail00"}
		{add_view	 "startsmoke_big"	"shooter01"	"tail01"}
		{add_view	 "startsmoke_big"	"shooter02"	"tail02"}
		{add_view	 "startsmoke_big"	"shooter03"	"tail03"}
		{add_view	 "startsmoke_big"	"shooter04"	"tail04"}
		{add_view	 "startsmoke_big"	"shooter05"	"tail05"}
		{add_view	 "startsmoke_big"	"shooter06"	"tail06"}
		{add_view	 "startsmoke_big"	"shooter07"	"tail07"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0"
				{delay 0.1 {spawn "aim7m_carrier" "shooter%0"   x}}
				{ani_play "fire"}
				{view start "shooter%0"}
				{delay 0.42
					{view pause "shooter%0"}
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
	}
}
{"searam"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter000"	"shooter000"}
		{add_view	 "flash_gun_big"	"shooter001"	"shooter001"}
		{add_view	 "flash_gun_big"	"shooter002"	"shooter002"}
		{add_view	 "flash_gun_big"	"shooter003"	"shooter003"}
		{add_view	 "flash_gun_big"	"shooter004"	"shooter004"}
		{add_view	 "flash_gun_big"	"shooter005"	"shooter005"}
		{add_view	 "flash_gun_big"	"shooter006"	"shooter006"}
		{add_view	 "flash_gun_big"	"shooter007"	"shooter007"}
		{add_view	 "flash_gun_big"	"shooter008"	"shooter008"}
		{add_view	 "flash_gun_big"	"shooter009"	"shooter009"}
		{add_view	 "flash_gun_big"	"shooter010"	"shooter010"}
		{add_view	 "flash_gun_big"	"shooter011"	"shooter011"}
		{add_view	 "flash_gun_big"	"shooter012"	"shooter012"}
		{add_view	 "flash_gun_big"	"shooter013"	"shooter013"}
		{add_view	 "flash_gun_big"	"shooter014"	"shooter014"}
		{add_view	 "flash_gun_big"	"shooter015"	"shooter015"}
		{add_view	 "flash_gun_big"	"shooter016"	"shooter016"}
		{add_view	 "flash_gun_big"	"shooter017"	"shooter017"}
		{add_view	 "flash_gun_big"	"shooter018"	"shooter018"}
		{add_view	 "flash_gun_big"	"shooter019"	"shooter019"}
		{add_view	 "flash_gun_big"	"shooter020"	"shooter020"}
		{add_view	 "startsmoke_big"	"shooter000"	"tail000"}
		{add_view	 "startsmoke_big"	"shooter001"	"tail001"}
		{add_view	 "startsmoke_big"	"shooter002"	"tail002"}
		{add_view	 "startsmoke_big"	"shooter003"	"tail003"}
		{add_view	 "startsmoke_big"	"shooter004"	"tail004"}
		{add_view	 "startsmoke_big"	"shooter005"	"tail005"}
		{add_view	 "startsmoke_big"	"shooter006"	"tail006"}
		{add_view	 "startsmoke_big"	"shooter007"	"tail007"}
		{add_view	 "startsmoke_big"	"shooter008"	"tail008"}
		{add_view	 "startsmoke_big"	"shooter009"	"tail009"}
		{add_view	 "startsmoke_big"	"shooter010"	"tail010"}
		{add_view	 "startsmoke_big"	"shooter011"	"tail011"}
		{add_view	 "startsmoke_big"	"shooter012"	"tail012"}
		{add_view	 "startsmoke_big"	"shooter013"	"tail013"}
		{add_view	 "startsmoke_big"	"shooter014"	"tail014"}
		{add_view	 "startsmoke_big"	"shooter015"	"tail015"}
		{add_view	 "startsmoke_big"	"shooter016"	"tail016"}
		{add_view	 "startsmoke_big"	"shooter017"	"tail017"}
		{add_view	 "startsmoke_big"	"shooter018"	"tail018"}
		{add_view	 "startsmoke_big"	"shooter019"	"tail019"}
		{add_view	 "startsmoke_big"	"shooter020"	"tail020"}
		}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0"
				{delay 0.05
					{spawn "poddon_cannon" "shooter0%0" x {impulse forward 2.5 0.5}}
					{spawn "poddon_cannon" "tail0%0" x {impulse forward 2.5 0.5}}
				}
				{delay 0.15 {spawn "rim116_carrier" "shooter0%0"   x}
					{view start "shooter0%0"}
					{delay 0.42
						{view pause "shooter0%0"}
					}
				}
		)
		{if ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)	
		  else ("fire_barrel" args 06)	
		  else ("fire_barrel" args 07)	
		  else ("fire_barrel" args 08)	
		  else ("fire_barrel" args 09)	
		  else ("fire_barrel" args 10)	
		  else ("fire_barrel" args 11)
		  else ("fire_barrel" args 12)
		  else ("fire_barrel" args 13)
		  else ("fire_barrel" args 14)
		  else ("fire_barrel" args 15)	
		  else ("fire_barrel" args 16)	
		  else ("fire_barrel" args 17)	
		  else ("fire_barrel" args 18)	
		  else ("fire_barrel" args 19)	
		  else ("fire_barrel" args 20)	
		}
	}
}
{"osa_ma_pu"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter00"	"shooter00"}
		{add_view	 "flash_gun_big"	"shooter01"	"shooter01"}
		{add_view	 "startsmoke_big"	"shooter00"	"tail00"}
		{add_view	 "startsmoke_big"	"shooter01"	"tail01"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0"
				{delay 0.1 {spawn "osa_missile_carrier" "shooter%0"   x}}
				{ani_play "fire"}
				{view start "shooter%0"}
				{delay 0.42
					{view pause "shooter%0"}
				}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}
}
{"uragan_pu"
	{on spawn
		{add_view	 "flash_gun_big"	"flashbarrel"	"foresight2"}
		{add_view	 "startsmoke_big"	"flashbarrel"	"tail"}
	}
	{on fire "gun2" 
;		{spawn "proj_probe" "foresight2"   x {tags add "shooter00"}}
		{set "gun2"}{call "proj_probe"}
		{view start "flashbarrel"}
		{delay 0.42 {view pause "flashbarrel"} }
	}
}
{"malahit_pu"
	{on spawn
		{add_view	 "flash_gun_big"	"shootera1"	"Missile1"}
		{add_view	 "flash_gun_big"	"shootera2"	"Missile2"}
		{add_view	 "flash_gun_big"	"shootera3"	"Missile3"}
		{add_view	 "flash_gun_big"	"shootera4"	"Missile4"}
		{add_view	 "flash_gun_big"	"shootera5"	"Missile5"}
		{add_view	 "flash_gun_big"	"shootera6"	"Missile6"}
		{add_view	 "sturmtiger_fire"	"shooter1"	"tail1"}
		{add_view	 "sturmtiger_fire"	"shooter2"	"tail2"}
		{add_view	 "sturmtiger_fire"	"shooter3"	"tail3"}
		{add_view	 "sturmtiger_fire"	"shooter4"	"tail4"}
		{add_view	 "sturmtiger_fire"	"shooter5"	"tail5"}
		{add_view	 "sturmtiger_fire"	"shooter6"	"tail6"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
				{ani_play "cover%0" 0.6}
				{delay 0.2 
					{ani_play "fire%0" 0.7}
					{view start "shooter%0"}
					{view start "shootera%0"}
					{delay 1
						{view pause "shootera%0"}
						{view pause "shooter%0"}
					}
				}
				{delay 0.65 
					{spawn "malahit_carrier" "Missile%0"   x}
					{bone hide "Missile%0"}
					{volumes "ammo_storage_main%0" disable contact bullet blast}
				}
			)
			{if name "00" ("fire_barrel" args 1)
			  else name "01" ("fire_barrel" args 2)
			  else name "02" ("fire_barrel" args 3)
			else name "03" ("fire_barrel" args 4)
			  else name "04" ("fire_barrel" args 5)
			 else name "05" ("fire_barrel" args 6)
			}
	}
}
{"rastrub_pu"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter00"	"shooter00"}
		{add_view	 "flash_gun_big"	"shooter01"	"shooter01"}
		{add_view	 "flash_gun_big"	"shooter02"	"shooter02"}
		{add_view	 "flash_gun_big"	"shooter03"	"shooter03"}
		{add_view	 "flash_gun_big"	"shooter04"	"shooter04"}
		{add_view	 "flash_gun_big"	"shooter05"	"shooter05"}
		{add_view	 "flash_gun_big"	"shooter06"	"shooter06"}
		{add_view	 "flash_gun_big"	"shooter07"	"shooter07"}
		{add_view	 "startsmoke_big"	"shooter00"	"tail00"}
		{add_view	 "startsmoke_big"	"shooter01"	"tail01"}
		{add_view	 "startsmoke_big"	"shooter02"	"tail02"}
		{add_view	 "startsmoke_big"	"shooter03"	"tail03"}
		{add_view	 "startsmoke_big"	"shooter04"	"tail04"}
		{add_view	 "startsmoke_big"	"shooter05"	"tail05"}
		{add_view	 "startsmoke_big"	"shooter06"	"tail06"}
		{add_view	 "startsmoke_big"	"shooter07"	"tail07"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0" 
				{ani_play "fire%0"}
				{delay 0.5 
					{if not tagged "launch_antiship" 
					{spawn "rastrub_carrier" "shooter%0"   x} {tags remove "launch_antiship"}
					else {spawn "rastrub_antiship_carrier" "shooter%0"   x}}
					{view start "shooter%0"}
					{delay 0.3
						{view pause "shooter%0"}
					}
				}
		)
			{if ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
}
{"moskit_pu"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter00"	"shooter00"}
		{add_view	 "flash_gun_big"	"shooter01"	"shooter01"}
		{add_view	 "flash_gun_big"	"shooter02"	"shooter02"}
		{add_view	 "flash_gun_big"	"shooter03"	"shooter03"}
		{add_view	 "flash_gun_big"	"shooter04"	"shooter04"}
		{add_view	 "flash_gun_big"	"shooter05"	"shooter05"}
		{add_view	 "flash_gun_big"	"shooter06"	"shooter06"}
		{add_view	 "flash_gun_big"	"shooter07"	"shooter07"}
		{add_view	 "startsmoke_big"	"shooter00"	"tail00"}
		{add_view	 "startsmoke_big"	"shooter01"	"tail01"}
		{add_view	 "startsmoke_big"	"shooter02"	"tail02"}
		{add_view	 "startsmoke_big"	"shooter03"	"tail03"}
		{add_view	 "startsmoke_big"	"shooter04"	"tail04"}
		{add_view	 "startsmoke_big"	"shooter05"	"tail05"}
		{add_view	 "startsmoke_big"	"shooter06"	"tail06"}
		{add_view	 "startsmoke_big"	"shooter07"	"tail07"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0" 
				{ani_play "fire%0"}
				{delay 0.5 
					{spawn "moskit_carrier" "shooter%0"   x}
					{view start "shooter%0"}
					{delay 0.3
						{view pause "shooter%0"}
					}
				}
		)
			{if ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
}
{"basalt_pu"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter00"	"shooter00"}
		{add_view	 "flash_gun_big"	"shooter01"	"shooter01"}
		{add_view	 "flash_gun_big"	"shooter02"	"shooter02"}
		{add_view	 "flash_gun_big"	"shooter03"	"shooter03"}
		{add_view	 "flash_gun_big"	"shooter04"	"shooter04"}
		{add_view	 "flash_gun_big"	"shooter05"	"shooter05"}
		{add_view	 "flash_gun_big"	"shooter06"	"shooter06"}
		{add_view	 "flash_gun_big"	"shooter07"	"shooter07"}
		{add_view	 "flash_gun_big"	"shooter08"	"shooter08"}
		{add_view	 "flash_gun_big"	"shooter09"	"shooter09"}
		{add_view	 "flash_gun_big"	"shooter10"	"shooter10"}
		{add_view	 "flash_gun_big"	"shooter11"	"shooter11"}
		{add_view	 "flash_gun_big"	"shooter12"	"shooter12"}
		{add_view	 "flash_gun_big"	"shooter13"	"shooter13"}
		{add_view	 "flash_gun_big"	"shooter14"	"shooter14"}
		{add_view	 "flash_gun_big"	"shooter15"	"shooter15"}

		{add_view	 "startsmoke_big"	"shooter00"	"tail00"}
		{add_view	 "startsmoke_big"	"shooter01"	"tail01"}
		{add_view	 "startsmoke_big"	"shooter02"	"tail02"}
		{add_view	 "startsmoke_big"	"shooter03"	"tail03"}
		{add_view	 "startsmoke_big"	"shooter04"	"tail04"}
		{add_view	 "startsmoke_big"	"shooter05"	"tail05"}
		{add_view	 "startsmoke_big"	"shooter06"	"tail06"}
		{add_view	 "startsmoke_big"	"shooter07"	"tail07"}
		{add_view	 "startsmoke_big"	"shooter08"	"tail08"}
		{add_view	 "startsmoke_big"	"shooter09"	"tail09"}
		{add_view	 "startsmoke_big"	"shooter10"	"tail10"}
		{add_view	 "startsmoke_big"	"shooter11"	"tail11"}
		{add_view	 "startsmoke_big"	"shooter12"	"tail12"}
		{add_view	 "startsmoke_big"	"shooter13"	"tail13"}
		{add_view	 "startsmoke_big"	"shooter14"	"tail14"}
		{add_view	 "startsmoke_big"	"shooter15"	"tail15"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0" 
				{ani_play "fire%0"}
				{delay 0.5 
					{spawn "basalt_p1000_carrier" "shooter%0"   x}
					{view start "shooter%0"}
					{delay 0.3
						{view pause "shooter%0"}
					}
				}
		)
			{if ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			  else ("fire_barrel" args 08)
			  else ("fire_barrel" args 09)
			  else ("fire_barrel" args 10)
			  else ("fire_barrel" args 11)
			  else ("fire_barrel" args 12)
			  else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			  else ("fire_barrel" args 15)
			}
	}
}
{"granit1144_pu"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter000"	"shooter000"}
		{add_view	 "flash_gun_big"	"shooter001"	"shooter001"}
		{add_view	 "flash_gun_big"	"shooter002"	"shooter002"}
		{add_view	 "flash_gun_big"	"shooter003"	"shooter003"}
		{add_view	 "flash_gun_big"	"shooter004"	"shooter004"}
		{add_view	 "flash_gun_big"	"shooter005"	"shooter005"}
		{add_view	 "flash_gun_big"	"shooter006"	"shooter006"}
		{add_view	 "flash_gun_big"	"shooter007"	"shooter007"}
		{add_view	 "flash_gun_big"	"shooter008"	"shooter008"}
		{add_view	 "flash_gun_big"	"shooter009"	"shooter009"}
		{add_view	 "flash_gun_big"	"shooter010"	"shooter010"}
		{add_view	 "flash_gun_big"	"shooter011"	"shooter011"}
		{add_view	 "flash_gun_big"	"shooter012"	"shooter012"}
		{add_view	 "flash_gun_big"	"shooter013"	"shooter013"}
		{add_view	 "flash_gun_big"	"shooter014"	"shooter014"}
		{add_view	 "flash_gun_big"	"shooter015"	"shooter015"}
		{add_view	 "flash_gun_big"	"shooter016"	"shooter016"}
		{add_view	 "flash_gun_big"	"shooter017"	"shooter017"}
		{add_view	 "flash_gun_big"	"shooter018"	"shooter018"}
		{add_view	 "flash_gun_big"	"shooter019"	"shooter019"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0" 
				{ani_play "fire%0"}
				{delay 0.5 
					{spawn "granit_carrier" "shooter0%0"   x}
					{view start "shooter0%0"}
					{delay 0.3
						{view pause "shooter0%0"}
					}
					{spawn "sturmtiger_fire" "shooter0%0"   x}
				}
		)
			{if ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			  else ("fire_barrel" args 08)
			  else ("fire_barrel" args 09)
			  else ("fire_barrel" args 10)
			  else ("fire_barrel" args 11)
			  else ("fire_barrel" args 12)
			  else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			  else ("fire_barrel" args 15)
			  else ("fire_barrel" args 16)
			  else ("fire_barrel" args 17)
			  else ("fire_barrel" args 18)
			  else ("fire_barrel" args 19)
			}
	}
}
{"phalanx"
	{on "add_gun_effects"
		{add_view	 "flash_gun_big"	"flashbarrel1"	"foresight1"}
	}
	{on fire "gun1"
		{spawn "autocannon_fire_smoke" "foresight1" x scale 2}
	}
}
{"mk38_mod2"
    ("25mm_bushmaster")
}
{"ak630"
	{on "add_gun_effects"
		{add_view	 "flash_gun_big"	"flashbarrel1"	"foresight1"}
	}
	{on fire "gun1"
		{spawn "autocannon_fire_smoke" "foresight1" x scale 2}
	}
}
{"kortik"
	{on "add_gun_effects"
		{add_view	 	"flash_gun_big"	"gun_flash00"		"shooter00"}
		{add_view	 	"flash_gun_big"	"gun_flash01"		"shooter01"}
		{add_view 	"rok_tail"		"tail00"			"tail00"}
		{add_view 	"rok_tail"		"tail01"			"tail01"}
		{add_view 	"rok_tail"		"tail02"			"tail02"}
		{add_view 	"rok_tail"		"tail03"			"tail03"}
		{add_view 	"rok_tail"		"tail04"			"tail04"}
		{add_view 	"rok_tail"		"tail05"			"tail05"}
		{add_view 	"rok_tail"		"tail06"			"tail06"}
		{add_view 	"rok_tail"		"tail07"			"tail07"}
	}
	{on fire "gun1" overload
		(define "fire_barrel"
			name "%0"
				{view start	"gun_flash%0"}
				{spawn "tank_canon_fire_small" "shooter%0"   x}
				{delay 0.2 {view pause	"gun_flash%0"}}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	
	{on fire "gun2" overload
		(define "fire_barrel"
			name "%0"
				{delay 0.1  {spawn "9m311_carrier" "R_shooter%0"   x}}
				{view start "tail%0"}
				{spawn "startsmoke" "R_shooter%0" x}
				{spawn "startsmoke" "tail%0" x}
				{delay 0.4
					{view pause "tail%0"}
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
	}
}
{"mk45"
    	{on fire "gun" 
		("tank_gun")
    	 	{spawn "canon_gaub_fire" "Foresight1" x}
	}
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}
{"ak176"
    	{on fire "gun" 
		("tank_gun")
    	{spawn "canon_gaub_fire" "Foresight1" x}
	}
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}
{"ak100_maingun"
    	{on fire "gun" 
		("tank_gun")
    	{spawn "canon_gaub_fire" "Foresight1" x}
	}
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}
{"ak130_maingun"
	(define "fire_barrel"
		{spawn "canon_gaub_fire" "Shooter%0" x}
	)
	("110-130mm_gilza")
	{on fire "gun" 
		{if name "00" ("fire_barrel" args 00)
			{ani_play "fire"}
		else name "01" ("fire_barrel" args 01)
		}
		{delay 0.10 "shell_off"
			{delay 0.3	{call "spawn_shell"}{call "spawn_shell"}}
		}
	}
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}
{"mk41_aegis"
	{on spawn		
		{volumes "gun_recoil" disable blast}
		{call "init_gun2"}
	}
	{on "init_gun2"
		{add_view	 "proj_jet_sam"	"exh_000"	"tail_000"}
		{add_view	 "proj_jet_sam"	"exh_001"	"tail_001"}
		{add_view	 "proj_jet_sam"	"exh_002"	"tail_002"}
		{add_view	 "proj_jet_sam"	"exh_003"	"tail_003"}
		{add_view	 "proj_jet_sam"	"exh_004"	"tail_004"}
		{add_view	 "proj_jet_sam"	"exh_005"	"tail_005"}
		{add_view	 "proj_jet_sam"	"exh_006"	"tail_006"}
		{add_view	 "proj_jet_sam"	"exh_007"	"tail_007"}
		{add_view	 "proj_jet_sam"	"exh_008"	"tail_008"}
		{add_view	 "proj_jet_sam"	"exh_009"	"tail_009"}
		{add_view	 "proj_jet_sam"	"exh_010"	"tail_010"}
		{add_view	 "proj_jet_sam"	"exh_011"	"tail_011"}
		{add_view	 "proj_jet_sam"	"exh_012"	"tail_012"}
		{add_view	 "proj_jet_sam"	"exh_013"	"tail_013"}
		{add_view	 "proj_jet_sam"	"exh_014"	"tail_014"}
		{add_view	 "proj_jet_sam"	"exh_015"	"tail_015"}
		{add_view	 "proj_jet_sam"	"exh_016"	"tail_016"}
		{add_view	 "proj_jet_sam"	"exh_017"	"tail_017"}
		{add_view	 "proj_jet_sam"	"exh_018"	"tail_018"}
		{add_view	 "proj_jet_sam"	"exh_019"	"tail_019"}
		{add_view	 "proj_jet_sam"	"exh_020"	"tail_020"}
		{add_view	 "proj_jet_sam"	"exh_021"	"tail_021"}
		{add_view	 "proj_jet_sam"	"exh_022"	"tail_022"}
		{add_view	 "proj_jet_sam"	"exh_023"	"tail_023"}
		{add_view	 "proj_jet_sam"	"exh_024"	"tail_024"}
		{add_view	 "proj_jet_sam"	"exh_025"	"tail_025"}
		{add_view	 "proj_jet_sam"	"exh_026"	"tail_026"}
		{add_view	 "proj_jet_sam"	"exh_027"	"tail_027"}
		{add_view	 "proj_jet_sam"	"exh_028"	"tail_028"}
		{add_view	 "proj_jet_sam"	"exh_029"	"tail_029"}
		{add_view	 "proj_jet_sam"	"exh_030"	"tail_030"}
		{add_view	 "proj_jet_sam"	"exh_031"	"tail_031"}
		{add_view	 "proj_jet_sam"	"exh_032"	"tail_032"}
		{add_view	 "proj_jet_sam"	"exh_033"	"tail_033"}
		{add_view	 "proj_jet_sam"	"exh_034"	"tail_034"}
		{add_view	 "proj_jet_sam"	"exh_035"	"tail_035"}
		{add_view	 "proj_jet_sam"	"exh_036"	"tail_036"}
		{add_view	 "proj_jet_sam"	"exh_037"	"tail_037"}
		{add_view	 "proj_jet_sam"	"exh_038"	"tail_038"}
		{add_view	 "proj_jet_sam"	"exh_039"	"tail_039"}
		{add_view	 "proj_jet_sam"	"exh_040"	"tail_040"}
		{add_view	 "proj_jet_sam"	"exh_041"	"tail_041"}
		{add_view	 "proj_jet_sam"	"exh_042"	"tail_042"}
		{add_view	 "proj_jet_sam"	"exh_043"	"tail_043"}
		{add_view	 "proj_jet_sam"	"exh_044"	"tail_044"}
		{add_view	 "proj_jet_sam"	"exh_045"	"tail_045"}
		{add_view	 "proj_jet_sam"	"exh_046"	"tail_046"}
		{add_view	 "proj_jet_sam"	"exh_047"	"tail_047"}
		{add_view	 "proj_jet_sam"	"exh_048"	"tail_048"}
		{add_view	 "proj_jet_sam"	"exh_049"	"tail_049"}
		{add_view	 "proj_jet_sam"	"exh_050"	"tail_050"}
		{add_view	 "proj_jet_sam"	"exh_051"	"tail_051"}
		{add_view	 "proj_jet_sam"	"exh_052"	"tail_052"}
		{add_view	 "proj_jet_sam"	"exh_053"	"tail_053"}
		{add_view	 "proj_jet_sam"	"exh_054"	"tail_054"}
		{add_view	 "proj_jet_sam"	"exh_055"	"tail_055"}
		{add_view	 "proj_jet_sam"	"exh_056"	"tail_056"}
		{add_view	 "proj_jet_sam"	"exh_057"	"tail_057"}
		{add_view	 "proj_jet_sam"	"exh_058"	"tail_058"}
		{add_view	 "proj_jet_sam"	"exh_059"	"tail_059"}
		{add_view	 "proj_jet_sam"	"exh_060"	"tail_060"}
		{add_view	 "proj_jet_sam"	"exh_061"	"tail_061"}
		{add_view	 "proj_jet_sam"	"exh_062"	"tail_062"}
		{add_view	 "proj_jet_sam"	"exh_063"	"tail_063"}
		
		{view hide	"exh_000"}
		{view hide	"exh_001"}
		{view hide	"exh_002"}
		{view hide	"exh_003"}
		{view hide	"exh_004"}
		{view hide	"exh_005"}
		{view hide	"exh_006"}
		{view hide	"exh_007"}
		{view hide	"exh_008"}
		{view hide	"exh_009"}
		{view hide	"exh_010"}
		{view hide	"exh_011"}
		{view hide	"exh_012"}
		{view hide	"exh_013"}
		{view hide	"exh_014"}
		{view hide	"exh_015"}
		{view hide	"exh_016"}
		{view hide	"exh_017"}
		{view hide	"exh_018"}
		{view hide	"exh_019"}
		{view hide	"exh_020"}
		{view hide	"exh_021"}
		{view hide	"exh_022"}
		{view hide	"exh_023"}
		{view hide	"exh_024"}
		{view hide	"exh_025"}
		{view hide	"exh_026"}
		{view hide	"exh_027"}
		{view hide	"exh_028"}
		{view hide	"exh_029"}
		{view hide	"exh_030"}
		{view hide	"exh_031"}
		{view hide	"exh_032"}
		{view hide	"exh_033"}
		{view hide	"exh_034"}
		{view hide	"exh_035"}
		{view hide	"exh_036"}
		{view hide	"exh_037"}
		{view hide	"exh_038"}
		{view hide	"exh_039"}
		{view hide	"exh_040"}
		{view hide	"exh_041"}
		{view hide	"exh_042"}
		{view hide	"exh_043"}
		{view hide	"exh_044"}
		{view hide	"exh_045"}
		{view hide	"exh_046"}
		{view hide	"exh_047"}
		{view hide	"exh_048"}
		{view hide	"exh_049"}
		{view hide	"exh_050"}
		{view hide	"exh_051"}
		{view hide	"exh_052"}
		{view hide	"exh_053"}
		{view hide	"exh_054"}
		{view hide	"exh_055"}
		{view hide	"exh_056"}
		{view hide	"exh_057"}
		{view hide	"exh_058"}
		{view hide	"exh_059"}
		{view hide	"exh_060"}
		{view hide	"exh_061"}
		{view hide	"exh_062"}
		{view hide	"exh_063"}
		
		{add_view	 "startsmoke_cali"	"tail_1"	"tail_1a"}
		{add_view	 "startsmoke_cali"	"tail_1"	"tail_1b"}
		{add_view	 "startsmoke_cali"	"tail_1"	"tail_1c"}
		{add_view	 "startsmoke_cali"	"tail_1"	"tail_1d"}
		{add_view	 "startsmoke_cali"	"tail_2"	"tail_2a"}
		{add_view	 "startsmoke_cali"	"tail_2"	"tail_2b"}
		{add_view	 "startsmoke_cali"	"tail_2"	"tail_2c"}
		{add_view	 "startsmoke_cali"	"tail_2"	"tail_2d"}
		{add_view	 "startsmoke_cali"	"tail_3"	"tail_3a"}
		{add_view	 "startsmoke_cali"	"tail_3"	"tail_3b"}
		{add_view	 "startsmoke_cali"	"tail_3"	"tail_3c"}
		{add_view	 "startsmoke_cali"	"tail_3"	"tail_3d"}
		{add_view	 "startsmoke_cali"	"tail_4"	"tail_4a"}
		{add_view	 "startsmoke_cali"	"tail_4"	"tail_4b"}
		{add_view	 "startsmoke_cali"	"tail_4"	"tail_4c"}
		{add_view	 "startsmoke_cali"	"tail_4"	"tail_4d"}
		{add_view	 "startsmoke_cali"	"tail_5"	"tail_5a"}
		{add_view	 "startsmoke_cali"	"tail_5"	"tail_5b"}
		{add_view	 "startsmoke_cali"	"tail_5"	"tail_5c"}
		{add_view	 "startsmoke_cali"	"tail_5"	"tail_5d"}
		{add_view	 "startsmoke_cali"	"tail_6"	"tail_6a"}
		{add_view	 "startsmoke_cali"	"tail_6"	"tail_6b"}
		{add_view	 "startsmoke_cali"	"tail_6"	"tail_6c"}
		{add_view	 "startsmoke_cali"	"tail_6"	"tail_6d"}
		{add_view	 "startsmoke_cali"	"tail_7"	"tail_7a"}
		{add_view	 "startsmoke_cali"	"tail_7"	"tail_7b"}
		{add_view	 "startsmoke_cali"	"tail_7"	"tail_7c"}
		{add_view	 "startsmoke_cali"	"tail_7"	"tail_7d"}
		{add_view	 "startsmoke_cali"	"tail_8"	"tail_8a"}
		{add_view	 "startsmoke_cali"	"tail_8"	"tail_8b"}
		{add_view	 "startsmoke_cali"	"tail_8"	"tail_8c"}
		{add_view	 "startsmoke_cali"	"tail_8"	"tail_8d"}
	}
	{on fire "gun2" 
;		{spawn "proj_probe" "Foresight1"   x}
		{set "gun2"}{call "proj_probe"}
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
	(define "fire_barrel"
		{delay 0.2 
			{volumes "gun_recoil" enable blast}
			{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
			{delay 0.5 {volumes "gun_recoil" disable blast}}
;			{add_view	 "proj_jet_sam"	"exh_0%shooter"	"tail_0%shooter"}
			{spawn "startsmoke_vert" "shooter_0%shooter" x}
			{view start "tail_%tail"}
			{view start "exh_0%shooter"}
			{bone show "%missile_vis%shooter"}
			
			{delay 0.38
				{bone hide "%missile_vis%shooter"}
				{view pause "tail_%tail"}
				{view pause "exh_0%shooter"}
				{view hide "exh_0%shooter"}
				{spawn "%missile_carrier" "shooter_0%shooter"   x}
			}
			{delay 0.45
				{ani_play "fire_restore"}
			}
			
		}
		{ani_play "fire_%shooter" 0.5}
		{ani_play "exhaust%tail" 0.5}
		{delay 0.4
			{view pause "tail_%tail"}
		}
	)
	(define "launch_block"
		{if rand 0.125 ("fire_barrel" shooter(%n0) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		else rand 0.25  ("fire_barrel" shooter(%n1) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		else rand 0.375  ("fire_barrel" shooter(%n2) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		else rand 0.5  ("fire_barrel" shooter(%n3) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		else rand 0.625  ("fire_barrel" shooter(%n4) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		else rand 0.75  ("fire_barrel" shooter(%n5) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		else rand 0.875  ("fire_barrel" shooter(%n6) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		else ("fire_barrel" shooter(%n7) tail(%tail) missile(%missile) missile_vis(%missile_vis))
		}
	)	
	(define "launch_missile"
		{if rand 0.5
			{if rand 0.25
				("launch_block" tail(1) missile(%missile) missile_vis(%missile_vis) n0(00) n1(01) n2(02) n3(03) n4(04) n5(05) n6(06) n7(07))
			else rand 0.33
				("launch_block" tail(2) missile(%missile) missile_vis(%missile_vis) n0(08) n1(09) n2(10) n3(11) n4(12) n5(13) n6(14) n7(15))
			else rand 0.5
				("launch_block" tail(3) missile(%missile) missile_vis(%missile_vis) n0(16) n1(17) n2(18) n3(19) n4(20) n5(21) n6(22) n7(23))
			else 
				("launch_block" tail(4) missile(%missile) missile_vis(%missile_vis) n0(24) n1(25) n2(26) n3(27) n4(28) n5(29) n6(30) n7(31))
			}
		else
			{if rand 0.25
				("launch_block" tail(5) missile(%missile) missile_vis(%missile_vis) n0(32) n1(33) n2(34) n3(35) n4(36) n5(37) n6(38) n7(39))
			else rand 0.33
				("launch_block" tail(6) missile(%missile) missile_vis(%missile_vis) n0(40) n1(41) n2(42) n3(43) n4(44) n5(45) n6(46) n7(47))
			else rand 0.5
				("launch_block" tail(7) missile(%missile) missile_vis(%missile_vis) n0(48) n1(49) n2(50) n3(51) n4(52) n5(53) n6(54) n7(55))
			else 
				("launch_block" tail(8) missile(%missile) missile_vis(%missile_vis) n0(56) n1(57) n2(58) n3(59) n4(60) n5(61) n6(62) n7(63))
			}		
		}
	)
	{on "launch_sm_2"
		("launch_missile" missile(sm_2er_blockiv) missile_vis(sm2er_0))
	}
	{on "launch_tomahawk"
		("launch_missile" missile(tomahawk) missile_vis(tomahawk_0))
	}
	{on "launch_asroc"
		("launch_missile" missile(asroc_vla) missile_vis(asroc0))
	}
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
	{on break overload
		{if component "gun_rot"
			{ik_enable "gun_rot" 0}
			{spawn "metal_hit_bul"}
			{call "update_turret"}
			{spawn "tank_die_particle" "body"}
			{spawn "circledust_norm" "body"}
			{view start "smoke3"}
			{delay 10
				{view stop "smoke3"}
			}
			{tags add "gun_rot_brake"}
			else {inherited}
		}
	}
}
{"mk41_32"
	(define "launch_missile32"
		{if rand 0.25
			("launch_block" tail(1) missile(%missile) missile_vis(%missile_vis) n0(00) n1(01) n2(02) n3(03) n4(04) n5(05) n6(06) n7(07))
		else rand 0.5
			("launch_block" tail(2) missile(%missile) missile_vis(%missile_vis) n0(08) n1(09) n2(10) n3(11) n4(12) n5(13) n6(14) n7(15))
		else rand 0.5
			("launch_block" tail(3) missile(%missile) missile_vis(%missile_vis) n0(16) n1(17) n2(18) n3(19) n4(20) n5(21) n6(22) n7(23))
		else 
			("launch_block" tail(4) missile(%missile) missile_vis(%missile_vis) n0(24) n1(25) n2(26) n3(27) n4(28) n5(29) n6(30) n7(31))
		}
	)
	{on "launch_sm_2" overload
		("launch_missile32" missile(sm_2er_blockiv) missile_vis(sm2er_0))
	}
	{on "launch_tomahawk" overload
		("launch_missile32" missile(tomahawk) missile_vis(tomahawk_0))
	}
	{on "launch_asroc" overload
		("launch_missile32" missile(asroc_vla) missile_vis(asroc0))
	}
}
{"laws"
	{on spawn
		{add_view "laser_big" "laser" "Foresight1"}
		{view hide "laser"}
	}
	{on fire "gun"
		{kill_delay "laser"}
		{view show "laser"}
		{delay 3 "laser"
			{view hide "laser"}
		}
	}
	{on "close"
		{ani_play "close"}
	}
	{on "open"
		{ani_play "close" -1}
	}
}
{"torpedotube_left"
	(define "temp_disable"
		{weapon_work "gun2" 0} {delay 2 {call "update_gun23"}}
	)
	{on ik begin "foresight1"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_left"} ("temp_disable")}}
	{on ik begin "foresight1_rot"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_left"} ("temp_disable")}}
	{on ik end "foresight1"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_left"} ("temp_disable")}}
	{on ik end "foresight1_rot"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_left"} ("temp_disable")}}
	{on "turn_back"
	  {delay 3 {ani_play "turn_left" -1}}
	}
}
{"torpedotube_right"
	{on ik begin "foresight1"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_right"} ("temp_disable")}}
	{on ik begin "foresight1_rot"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_right"} ("temp_disable")}}
	{on ik end "foresight1"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_right"} ("temp_disable")}}
	{on ik end "foresight1_rot"	{if not flag "radar_up"	{set "radar_up" 1}	{ani_play "turn_right"} ("temp_disable")}}
	{on "turn_back"
	  {delay 3 {ani_play "turn_right" -1}}
	}
}
{"mk32_torpedotube"
	{on spawn
		{add_view	 "powdersmoke_big"	"shooter00"	"shooter_00"}
		{add_view	 "powdersmoke_big"	"shooter01"	"shooter_01"}
		{add_view	 "powdersmoke_big"	"shooter02"	"shooter_02"}
	}
    	{on fire "gun2" 
		(define "fire_barrel"
			name "%0"
				{delay 0.1 {spawn "torpedo_mk46_spawner" "shooter_%0" x no_normal no_position}}
				{view start "shooter%0"}
				{delay 0.42
					{view pause "shooter%0"}
				}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			}
	}
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}
{"torpedo_mk46_spawner"
	{on spawn {ani_play "start" callback}}
	{on animation_end "start"
		{spawn "torpedo_mk46" "body" x no_normal no_position}
		{delete}
	}
}
{"torpedotube_rus"
	{on spawn
		{add_view	 "powdersmoke_big"	"shooter00"	"shooter_000"}
		{add_view	 "powdersmoke_big"	"shooter01"	"shooter_001"}
		{add_view	 "powdersmoke_big"	"shooter02"	"shooter_002"}
		{add_view	 "powdersmoke_big"	"shooter03"	"shooter_003"}
		{add_view	 "powdersmoke_big"	"shooter04"	"shooter_004"}
	}
    	{on fire "gun2" 
		(define "fire_barrel"
			name "%0"
;				{spawn "proj_probe" "foresight1"   x {tags add "shooter%0"}}
				{set "gun2"}{call "proj_probe"}
				{view start "shooter%0"}
				{delay 0.42
					{view pause "shooter%0"}
				}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			}
	}
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}
{"torpedotube_rus_x2_left" {on fire "gun2" {if name "01" {call "turn_back"}}}}
{"torpedotube_rus_x2_right" {on fire "gun2" {if name "01" {call "turn_back"}}}}
{"torpedotube_rus_x4_left" {on fire "gun2" {if name "03" {call "turn_back"}}}}
{"torpedotube_rus_x4_right" {on fire "gun2" {if name "03" {call "turn_back"}}}}
{"torpedotube_rus_x5_left" {on fire "gun2" {if name "04" {call "turn_back"}}}}
{"torpedotube_rus_x5_right" {on fire "gun2" {if name "04" {call "turn_back"}}}}
{"53_65k_torpedo_spawner"
	{on spawn 
		{if altitude 1
			{ani_play "start" callback}
		else altitude -10
			{ani_play "start_direct" callback}
		else
			{ani_play "start_up" callback}
		}
	}
	{on animation_end "start"
		{spawn "53_65k_torpedo" "body1" x no_normal no_position}
		{delete}
	}
	{on animation_end "start_direct"
		{spawn "53_65k_torpedo" "body1" x no_normal no_position {tags add "spawn_underwater"}}
		{delete}
	}
	{on animation_end "start_up"
		{spawn "53_65k_torpedo" "body1" x no_normal no_position {tags add "spawn_underwater"}}
		{delete}
	}
}
{"mk48_torpedo_spawner"
	{on spawn 
		{if altitude 1
			{ani_play "start" callback}
		else altitude -10
			{ani_play "start_direct" callback}
		else
			{ani_play "start_up" callback}
		}
	}
	{on animation_end "start"
		{spawn "mk48_torpedo" "body1" x no_normal no_position}
		{delete}
	}
	{on animation_end "start_direct"
		{spawn "mk48_torpedo" "body1" x no_normal no_position {tags add "spawn_underwater"}}
		{delete}
	}
	{on animation_end "start_up"
		{spawn "mk48_torpedo" "body1" x no_normal no_position {tags add "spawn_underwater"}}
		{delete}
	}
}

{"patriot_launcher"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter00"	"shooter00"}
		{add_view	 "flash_gun_big"	"shooter01"	"shooter01"}
		{add_view	 "flash_gun_big"	"shooter02"	"shooter02"}
		{add_view	 "flash_gun_big"	"shooter03"	"shooter03"}
		{add_view	 "startsmoke_big"	"shooter00"	"tail00"}
		{add_view	 "startsmoke_big"	"shooter01"	"tail01"}
		{add_view	 "startsmoke_big"	"shooter02"	"tail02"}
		{add_view	 "startsmoke_big"	"shooter03"	"tail03"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "shooter%0"   x}
				{delay 0.1 {spawn "patriot_carrier" "shooter%0"   x}}
;				{delay 0.1 {spawn "patriot_carrier" "foresight1"   x}}
				{view start "shooter%0"}
				{spawn "dust_shot_big_2" "basis"}
				{delay 0.42
					{view pause "shooter%0"}
				}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			}
			("cw_check_shooting" weap_id(gun2))
	}
}
{"patriot_radar"
	{on fire "radar"
		{ik_enable "turret" 0}
		{delay 5 {call "update_turret"}}
		("cw_check_shooting" weap_id(radar))
	}
	("radar_params" triplex(commander_triplex) visor(visor1) anim_rotate(radar) marker(antirad_generator_large_usa))
	{on "update_radar"
		{if tagged "radar_off" {weapon_work "radar" 0}
		else not work "commander_triplex" {weapon_work "radar" 0}
		else not work "body" {weapon_work "radar" 0}
		else not work "turret" {weapon_work "radar" 0}
		else tagged "no_power" {weapon_work "radar" 0}
		else {weapon_work "radar" 1}
		}
	}
}
{"hawk_rls_units"
	{on spawn {delay 0.1 {call "check_unlink"}}}
	("radar_params" triplex(commander_triplex) visor(visor1) anim_rotate(radar) marker(antirad_generator_large_usa))
	{on "check_unlink"
		{delay 3	
		       {if linked  {call "cwsh_radar_off"}
			   else {if not tagged "cwsh_passive" {if tagged "radar_off"{call "cwsh_radar_on"}}}}
		       {call "check_unlink"}
		}
	}
	{on "_explosion"
		{impulse up 0.1}
	}
}

{"exactor_mk2"
	{on spawn
		{add_view	 "flash_gun_big"	"shooter00"	"shooter00"}
		{add_view	 "flash_gun_big"	"shooter01"	"shooter01"}
		{add_view	 "flash_gun_big"	"shooter02"	"shooter02"}
		{add_view	 "flash_gun_big"	"shooter03"	"shooter03"}
		{add_view	 "startsmoke_big"	"shooter00"	"tail00"}
		{add_view	 "startsmoke_big"	"shooter01"	"tail01"}
		{add_view	 "startsmoke_big"	"shooter02"	"tail02"}
		{add_view	 "startsmoke_big"	"shooter03"	"tail03"}
	}
	{on fire "gun2" 
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "shooter%0"   x}
;				{spawn "proj_probe" "foresight1"   x {tags add "shooter%0"}}
				{set "gun2"}{call "proj_probe"}
				{view start "shooter%0"}
				{delay 0.42
					{view pause "shooter%0"}
				}
		)
		{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
		}
		("cw_check_shooting" weap_id(gun2))
	}
	{on "update_gun23" overload
		{if tagged "smalluav_no_connect" {weapon_work "gun2" 0}
		else {inherited}
		}
	}
}
{"osa_am_rls"
	{on spawn
		{if work "driver_triplex"	{ani_play "radar" loop}}
	}
	{on break
		{if component "driver_triplex"
			{if not tagged "driver_triplex_break"
				{bone cut "visor1"}
				{ani_stop "radar"}
			}
		else component "commander_triplex"
			{if not tagged "commander_triplex_break"
				{bone cut "visor2"}
				{bone cut "foresight2"}
			}
		}
	}
	{on "mp_destroy"
		{components "driver_triplex" break}
	}
}
{"ak630_rls"
	{on spawn
		{call "update_radar"}
	}
	{on ik begin "turret" 
		{ani_stop "radar"} 
		{kill_delay "update_radar"}
		{delay 5 "update_radar" {call "update_radar"}}
	}
	{on ik begin "gun_rot"
		{ani_stop "radar"} 
		{kill_delay "update_radar"}
		{delay 5 "update_radar" {call "update_radar"}}
	}
	{on "update_radar"
		{if work "commander_triplex"	{ani_play "radar" loop}}
	}
	{on break
		{if component "commander_triplex"
			{if not tagged "commander_triplex_break"
				{bone cut "visor2"}
				{bone cut "foresight2"}
				{ani_stop "radar"}
			}
		}
	}
	{on "mp_destroy"
		{components "commander_triplex" break}
	}
}
{"survey_rls"
	{on spawn
		{if work "commander_triplex"	{ani_play "radar" loop}} 
	}
	{on break
		{if component "commander_triplex"
			{if not tagged "commander_triplex_break"
				{bone cut "visor2"}
				{bone cut "foresight2"}
				{ani_stop "radar"}
			}
		}
	}
	{on "mp_destroy"
		{components "commander_triplex" break}
	}
}
{"a22_ogon"
	{on spawn
		{add_view 	"startsmoke_big" 		"rok_tail00" 		"tail00"}
		{add_view 	"startsmoke_big" 		"rok_tail01" 		"tail01"}
		{add_view 	"startsmoke_big" 		"rok_tail02" 		"tail02"}
		{add_view 	"startsmoke_big" 		"rok_tail03" 		"tail03"}
		{add_view 	"startsmoke_big" 		"rok_tail04" 		"tail04"}
		{add_view 	"startsmoke_big" 		"rok_tail05" 		"tail05"}
		{add_view 	"startsmoke_big" 		"rok_tail06" 		"tail06"}
		{add_view 	"startsmoke_big" 		"rok_tail07" 		"tail07"}
		{add_view 	"startsmoke_big" 		"rok_tail08" 		"tail08"}
		{add_view 	"startsmoke_big" 		"rok_tail09" 		"tail09"}
		{add_view 	"startsmoke_big" 		"rok_tail10" 		"tail10"}
		{add_view 	"startsmoke_big" 		"rok_tail11" 		"tail11"}
		{add_view 	"startsmoke_big" 		"rok_tail12" 		"tail12"}
		{add_view 	"startsmoke_big" 		"rok_tail13" 		"tail13"}
		{add_view 	"startsmoke_big" 		"rok_tail14" 		"tail14"}
		{add_view 	"startsmoke_big" 		"rok_tail15" 		"tail15"}
		{add_view 	"startsmoke_big" 		"rok_tail16" 		"tail16"}
		{add_view 	"startsmoke_big" 		"rok_tail17" 		"tail17"}
		{add_view 	"startsmoke_big" 		"rok_tail18" 		"tail18"}
		{add_view 	"startsmoke_big" 		"rok_tail19" 		"tail19"}
		{add_view 	"startsmoke_big" 		"rok_tail20" 		"tail20"}
		{add_view 	"startsmoke_big" 		"rok_tail21" 		"tail21"}
	}
	{on fire "gun2" 
		{spawn "startsmoke_big"}
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
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
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			}
	}
}
{"bomb_launcher"
	{on spawn
		{add_view 	"startsmoke_big" 		"rok_tail00" 		"tail00"}
		{add_view 	"startsmoke_big" 		"rok_tail01" 		"tail01"}
		{add_view 	"startsmoke_big" 		"rok_tail02" 		"tail02"}
		{add_view 	"startsmoke_big" 		"rok_tail03" 		"tail03"}
		{add_view 	"startsmoke_big" 		"rok_tail04" 		"tail04"}
		{add_view 	"startsmoke_big" 		"rok_tail05" 		"tail05"}
		{add_view 	"startsmoke_big" 		"rok_tail06" 		"tail06"}
		{add_view 	"startsmoke_big" 		"rok_tail07" 		"tail07"}
		{add_view 	"startsmoke_big" 		"rok_tail08" 		"tail08"}
		{add_view 	"startsmoke_big" 		"rok_tail09" 		"tail09"}
		{add_view 	"startsmoke_big" 		"rok_tail10" 		"tail10"}
		{add_view 	"startsmoke_big" 		"rok_tail11" 		"tail11"}
	}
	{on fire "gun2" 
		{spawn "startsmoke_big"}
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
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
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			}
	}
}
{"kinjal_pu"
	{on spawn		
		{volumes "gun_recoil" disable blast}
		{call "init_gun2"}
	}
	(define "fire_barrel"
		{delay 0.2 
			{volumes "gun_recoil" enable blast}
			{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
			{delay 0.5 {volumes "gun_recoil" disable blast}}
			{spawn "startsmoke_vert" "missile_nvis_0%shooter" x}
			{bone show "kinzal_0%shooter"}
			{delay 0.05 {spawn "tank_canon_fire_small" "tail_0%shooter" x}}
			{delay 0.30 {spawn "tank_canon_fire_small" "tail_0%shooter" x}}
			{delay 0.45
				{bone hide "kinzal_0%shooter"}
				{spawn "9m330_carrier" "shooter_0%shooter"   x}
			}
			{delay 0.49
				{ani_play "fire_restore"}
			}
		}
		{ani_play "fire_%shooter" 0.5}
	)
	{on fire "gun2" 
		{if name "00" ("fire_barrel" shooter(00))
		else name "01" ("fire_barrel" shooter(01))
		else name "02" ("fire_barrel" shooter(02))
		else name "03" ("fire_barrel" shooter(03))
		else name "04" ("fire_barrel" shooter(04))
		else name "05" ("fire_barrel" shooter(05))
		else name "06" ("fire_barrel" shooter(06))
		else name "07" ("fire_barrel" shooter(07))
		}
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
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}
{"s300f_pu"
	{on "init_gun2"
;		{add_view	 "proj_jet_sam"	"exh_000"	"tail_000"}
;		{add_view	 "proj_jet_sam"	"exh_001"	"tail_001"}
;		{add_view	 "proj_jet_sam"	"exh_002"	"tail_002"}
;		{add_view	 "proj_jet_sam"	"exh_003"	"tail_003"}
;		{add_view	 "proj_jet_sam"	"exh_004"	"tail_004"}
;		{add_view	 "proj_jet_sam"	"exh_005"	"tail_005"}
;		{add_view	 "proj_jet_sam"	"exh_006"	"tail_006"}
;		{add_view	 "proj_jet_sam"	"exh_007"	"tail_007"}
;		{add_view	 "proj_jet_sam"	"exh_008"	"tail_008"}
;		{add_view	 "proj_jet_sam"	"exh_009"	"tail_009"}
;		{add_view	 "proj_jet_sam"	"exh_010"	"tail_010"}
;		{add_view	 "proj_jet_sam"	"exh_011"	"tail_011"}

;		{view hide	"exh_000"}
;		{view hide	"exh_001"}
;		{view hide	"exh_002"}
;		{view hide	"exh_003"}
;		{view hide	"exh_004"}
;		{view hide	"exh_005"}
;		{view hide	"exh_006"}
;		{view hide	"exh_007"}
;		{view hide	"exh_008"}
;		{view hide	"exh_009"}
;		{view hide	"exh_010"}
;		{view hide	"exh_011"}
	}
	{on spawn		
		{volumes "gun_recoil" disable blast}
		{call "init_gun2"}
	}
	(define "fire_barrel"
		{delay 0.2 
			{volumes "gun_recoil" enable blast}
			{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
			{delay 0.5 {volumes "gun_recoil" disable blast}}
			{delay 0.1 {spawn "startsmoke_vert" "Shooter_0%shooter" x}}
			{bone show "missile_0%shooter"}
			{delay 0.65 
				{add_view	 "proj_jet_sam"	"exh_0%shooter"	"tail_0%shooter"}
				{view start "exh_0%shooter"}
;			{view show "exh_0%shooter"}
			
			}
			{delay 0.65 {spawn "tank_canon_fire_small" "tail_0%shooter" x}}
			{delay 1.65
				{bone hide "missile_0%shooter"}
				{spawn "48n6_carrier" "shooter_0%shooter"   x}
				{view pause "exh_0%shooter"}
				{view hide "exh_0%shooter"}
				{view stop "exh_0%shooter"}
			}
			{delay 1.69
				{ani_play "fire_restore"}
			}
		}
		{ani_play "fire_%shooter" 0.5}
	)
	{on fire "gun2" 
		{if name "00" ("fire_barrel" shooter(00))
		else name "01" ("fire_barrel" shooter(01))
		else name "02" ("fire_barrel" shooter(02))
		else name "03" ("fire_barrel" shooter(03))
		else name "04" ("fire_barrel" shooter(04))
		else name "05" ("fire_barrel" shooter(05))
		else name "06" ("fire_barrel" shooter(06))
		else name "07" ("fire_barrel" shooter(07))
		else name "08" ("fire_barrel" shooter(08))
		else name "09" ("fire_barrel" shooter(09))
		else name "10" ("fire_barrel" shooter(10))
		else name "11" ("fire_barrel" shooter(11))
		}
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
	{on "explosion"
		{spawn "ex_air_big2" "basis"}
	}
}