describe("Playlist", function() {
    let playlist, song;
    beforeEach(function(){
    playlist = new Playlist();
    song = new Song("Pink Floyd", "The dark side of the moon", "Rock");
});
    it("should be able to add song to playlist", function() {
        playlist.addSong(song);
        expect(playlist.getSong(0)).toBe(song);
    });
    it("should be able to delete a song from playlist", function() {
        playlist.addSong(song);
        playlist.removeSong(0);
        expect(playlist.getSong(0)).not.toBeDefined();
    });
});
