/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wav_audio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:04:29 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/16 17:12:12 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static	Uint8 *g_audio_pos;
static	Uint32 g_audio_len;

void	my_audio_callback(void *userdata, Uint8 *stream, int len)
{
	if (g_audio_len == 0)
		return ;
	if (len > (int)g_audio_len)
		len = g_audio_len;
	SDL_memcpy(stream, g_audio_pos, len);
	SDL_MixAudio(stream, g_audio_pos, len, SDL_MIX_MAXVOLUME);
	g_audio_pos += len;
	g_audio_len -= len;
	if (userdata)
		;
}

int		sound(void)
{
	static Uint32			wav_length;
	static Uint8			*wav_buffer;
	static SDL_AudioSpec	wav_spec;

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return (1);
	close(2);
	if (SDL_LoadWAV("source/1.wav",
					&wav_spec, &wav_buffer, &wav_length) == NULL)
		return (1);
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;
	g_audio_pos = wav_buffer;
	g_audio_len = wav_length;
	if (SDL_OpenAudio(&wav_spec, NULL) < 0)
	{
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		exit(-1);
	}
	SDL_PauseAudio(0);
	while (g_audio_len > 0)
		SDL_Delay(100);
	SDL_CloseAudio();
	SDL_FreeWAV(wav_buffer);
	return (0);
}
