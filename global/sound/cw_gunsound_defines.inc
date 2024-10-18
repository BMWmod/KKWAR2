(define "cw_gun_loudness"
	{loudness "%name_close"
		{group "shot"}
		{playback_limit
			{max_count 2}
			{discard_type stop_oldest}
		}
		{volume_attenuation table 
			(* 0		%range_k)	(*(* 1		%volume_k) 1)
			(* 50		%range_k)	(*(* 1		%volume_k) 1)
			(* 100		%range_k)	(*(* 1		%volume_k) 0.9)
			(* 150		%range_k)	(*(* 1		%volume_k) 0.8)
			(* 200		%range_k)	(*(* 0.5		%volume_k) 0.7)
			(* 300		%range_k)	(*(* 0		%volume_k) 0.6)
			(* 350		%range_k)	(*(* 0		%volume_k) 0.55)
			(* 400		%range_k)	(*(* 0		%volume_k) 0.5)
			(* 500		%range_k)	(*(* 0		%volume_k) 0.45)
			(* 600		%range_k)	(*(* 0		%volume_k) 0.4)
			(* 700		%range_k)	(*(* 0		%volume_k) 0.3)
			(* 800		%range_k)	(*(* 0		%volume_k) 0.2)
			(* 899		%range_k)	(*(* 0		%volume_k) 0.1)
		}
		("hdr_%name")
	}
	{loudness "%name_medium"
		{group "shot"}
		{playback_limit
			{max_count 2}
			{discard_type stop_oldest}
		}
		{volume_attenuation table 
			(* 0		%range_k)	(*(* 0		%volume_k) 1)
			(* 50		%range_k)	(*(* 0		%volume_k) 1)
			(* 100		%range_k)	(*(* 0		%volume_k) 0.9)
			(* 150		%range_k)	(*(* 0		%volume_k) 0.8)
			(* 200		%range_k)	(*(* 0.5		%volume_k) 0.7)
			(* 300		%range_k)	(*(* 1		%volume_k) 0.6)
			(* 350		%range_k)	(*(* 0.5		%volume_k) 0.55)
			(* 400		%range_k)	(*(* 0		%volume_k) 0.5)
			(* 500		%range_k)	(*(* 0		%volume_k) 0.45)
			(* 600		%range_k)	(*(* 0		%volume_k) 0.4)
			(* 700		%range_k)	(*(* 0		%volume_k) 0.3)
			(* 800		%range_k)	(*(* 0		%volume_k) 0.2)
			(* 899		%range_k)	(*(* 0		%volume_k) 0.1)
		}
		("hdr_%name")
	}
	{loudness "%name_far"
		{playback_limit
			{max_count 2}
			{discard_type stop_oldest}
		}
		{volume_attenuation table 
			(* 0		%range_k)	(*(* 0		%volume_k) 1)
			(* 50		%range_k)	(*(* 0		%volume_k) 1)
			(* 100		%range_k)	(*(* 0		%volume_k) 0.9)
			(* 150		%range_k)	(*(* 0		%volume_k) 0.8)
			(* 200		%range_k)	(*(* 0		%volume_k) 0.7)
			(* 300		%range_k)	(*(* 0		%volume_k) 0.6)
			(* 350		%range_k)	(*(* 0.5		%volume_k) 0.55)
			(* 400		%range_k)	(*(* 1		%volume_k) 0.5)
			(* 500		%range_k)	(*(* 0.5		%volume_k) 0.45)
			(* 600		%range_k)	(*(* 0.25		%volume_k) 0.4)
			(* 700		%range_k)	(*(* 0		%volume_k) 0.3)
			(* 800		%range_k)	(*(* 0		%volume_k) 0.2)
			(* 899		%range_k)	(*(* 0		%volume_k) 0.1)
		}
		("hdr_%name")
	}
	{loudness "%name_distant"
		{playback_limit
			{max_count 2}
			{discard_type stop_oldest}
		}
		{volume_attenuation table 
			(* 0		%range_k)	(*(* 0		%volume_k) 1)
			(* 50		%range_k)	(*(* 0		%volume_k) 1)
			(* 100		%range_k)	(*(* 0		%volume_k) 0.9)
			(* 150		%range_k)	(*(* 0		%volume_k) 0.8)
			(* 200		%range_k)	(*(* 0		%volume_k) 0.7)
			(* 300		%range_k)	(*(* 0		%volume_k) 0.6)
			(* 350		%range_k)	(*(* 0		%volume_k) 0.55)
			(* 400		%range_k)	(*(* 0		%volume_k) 0.5)
			(* 500		%range_k)	(*(* 0.5		%volume_k) 0.45)
			(* 600		%range_k)	(*(* 0.75		%volume_k) 0.4)
			(* 700		%range_k)	(*(* 1		%volume_k) 0.3)
			(* 800		%range_k)	(*(* 0.5		%volume_k) 0.2)
			(* 899		%range_k)	(*(* 0		%volume_k) 0.1)
		}
		("hdr_%name")
	}
)