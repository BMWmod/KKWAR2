(define "hdr_hmissile"
	{loudness 72}
	{loudness_envelope 
		0 	0
		0.75   	0
		1	-72
	}
	{loudness_attenuation table
		0	0
		25	0
		50	-12
		75	-72
	}
	{hdr "default" {output "environment" "footstep"}}
)

("cw_gun_loudness" name(hmissile) range_k(0.65) volume_k(0.9))